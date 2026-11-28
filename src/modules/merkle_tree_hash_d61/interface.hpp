#pragma once
#include "types.hpp"
#include "errors.hpp"

namespace codes_merkle_tree_hash_d61 {
class MerkleTree {
public:
    explicit MerkleTree(const std::vector<std::string>& leaves);
    std::uint64_t root() const;
    std::size_t leaf_count() const;
    std::vector<MerkleProofStep> proof(std::size_t index) const;
    bool verify(std::size_t index, const std::string& leaf, const std::vector<MerkleProofStep>& proof) const;
private:
    std::vector<std::uint64_t> leaves_;
    std::vector<std::vector<std::uint64_t>> levels_;
    static std::uint64_t hash_leaf(const std::string& s);
    static std::uint64_t mix(std::uint64_t a, std::uint64_t b);
};

void validate_problem_size(int n);
std::int64_t fast_checksum_span(const std::vector<std::int64_t>& xs);
std::vector<std::int64_t> parallel_checksum_batches(const std::vector<std::vector<std::int64_t>>& batches);
void verify_module_postcondition(bool ok, const char* msg);
} // namespace codes_merkle_tree_hash_d61
