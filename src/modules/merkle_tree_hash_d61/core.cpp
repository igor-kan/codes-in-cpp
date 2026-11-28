#include "interface.hpp"
#include <algorithm>
#include <cmath>
#include <limits>
#include <numeric>
#include <queue>

namespace codes_merkle_tree_hash_d61 {

std::uint64_t MerkleTree::hash_leaf(const std::string& s) {
    std::uint64_t h = 1469598103934665603ULL;
    for (std::size_t i = 0; i < s.size(); ++i) {
        h ^= static_cast<unsigned char>(s[i]);
        h *= 1099511628211ULL;
    }
    return h;
}
std::uint64_t MerkleTree::mix(std::uint64_t a, std::uint64_t b) {
    std::uint64_t h = a ^ 0x9e3779b97f4a7c15ULL;
    h ^= b + 0x9e3779b97f4a7c15ULL + (h << 6) + (h >> 2);
    return h;
}
MerkleTree::MerkleTree(const std::vector<std::string>& leaves) {
    for (std::size_t i = 0; i < leaves.size(); ++i) leaves_.push_back(hash_leaf(leaves[i]));
    if (leaves_.empty()) return;
    levels_.push_back(leaves_);
    while (levels_.back().size() > 1) {
        std::vector<std::uint64_t> cur = levels_.back();
        if (cur.size() % 2 == 1) cur.push_back(cur.back());
        std::vector<std::uint64_t> nxt;
        nxt.reserve(cur.size() / 2);
        for (std::size_t i = 0; i < cur.size(); i += 2) nxt.push_back(mix(cur[i], cur[i + 1]));
        levels_.push_back(nxt);
    }
}
std::uint64_t MerkleTree::root() const {
    return levels_.empty() ? 0 : levels_.back()[0];
}
std::size_t MerkleTree::leaf_count() const {
    return leaves_.size();
}
std::vector<MerkleProofStep> MerkleTree::proof(std::size_t index) const {
    std::vector<MerkleProofStep> out;
    if (levels_.empty() || index >= leaves_.size()) return out;
    std::size_t idx = index;
    for (std::size_t lvl = 0; lvl + 1 < levels_.size(); ++lvl) {
        const std::vector<std::uint64_t>& cur = levels_[lvl];
        std::size_t sib = 0;
        bool is_left = false;
        if (idx % 2 == 0) {
            sib = (idx + 1 < cur.size()) ? idx + 1 : idx;
            is_left = false;
        } else {
            sib = idx - 1;
            is_left = true;
        }
        out.push_back(MerkleProofStep{cur[sib], is_left});
        idx /= 2;
    }
    return out;
}
bool MerkleTree::verify(std::size_t index, const std::string& leaf, const std::vector<MerkleProofStep>& proof) const {
    if (index >= leaves_.size()) return false;
    std::uint64_t h = hash_leaf(leaf);
    for (std::size_t i = 0; i < proof.size(); ++i) {
        h = proof[i].is_left ? mix(proof[i].sibling, h) : mix(h, proof[i].sibling);
    }
    return h == root();
}

} // namespace codes_merkle_tree_hash_d61
