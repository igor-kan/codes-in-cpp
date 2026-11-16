#include "interface.hpp"
#include <algorithm>
#include <array>

namespace codes_huffman_adaptive_vitter {
namespace {
struct DynTree {
    static constexpr int MAX_NODES = 513;
    std::array<AdaptiveNode, MAX_NODES> nodes{};
    std::array<int, 256> sym_idx{};
    int root = 0;
    int nyt = 0;
    int next_order = 512;

    DynTree() {
        sym_idx.fill(-1);
        nodes[MAX_NODES - 1] = AdaptiveNode{-1, -1, -1, 0, -2};
        root = MAX_NODES - 1;
        nyt = MAX_NODES - 1;
        next_order = MAX_NODES - 2;
    }

    int find_leader(int idx) const {
        int w = nodes[static_cast<std::size_t>(idx)].weight;
        int best = idx;
        for (int j = idx + 1; j <= root; ++j) {
            if (nodes[static_cast<std::size_t>(j)].weight == w) best = j;
            else break;
        }
        return best;
    }

    bool is_ancestor(int anc, int node) const {
        while (node != -1) {
            if (node == anc) return true;
            node = nodes[static_cast<std::size_t>(node)].parent;
        }
        return false;
    }

    void swap_subtrees(int a, int b) {
        if (a == b) return;
        std::swap(nodes[static_cast<std::size_t>(a)].symbol, nodes[static_cast<std::size_t>(b)].symbol);
        std::swap(nodes[static_cast<std::size_t>(a)].left, nodes[static_cast<std::size_t>(b)].left);
        std::swap(nodes[static_cast<std::size_t>(a)].right, nodes[static_cast<std::size_t>(b)].right);
        auto fix = [&](int id) {
            auto& nd = nodes[static_cast<std::size_t>(id)];
            if (nd.symbol >= 0) sym_idx[static_cast<std::size_t>(nd.symbol)] = id;
            if (nd.symbol == -2) nyt = id;
            if (nd.left >= 0) nodes[static_cast<std::size_t>(nd.left)].parent = id;
            if (nd.right >= 0) nodes[static_cast<std::size_t>(nd.right)].parent = id;
        };
        fix(a);
        fix(b);
    }

    void update(uint8_t sym) {
        int cur = sym_idx[sym];
        if (cur == -1) {
            int old_nyt = nyt;
            int new_leaf = next_order--;
            int new_nyt = next_order--;
            nodes[static_cast<std::size_t>(old_nyt)].symbol = -1;
            nodes[static_cast<std::size_t>(old_nyt)].right = new_leaf;
            nodes[static_cast<std::size_t>(old_nyt)].left = new_nyt;
            nodes[static_cast<std::size_t>(new_leaf)] = AdaptiveNode{old_nyt, -1, -1, 1, sym};
            nodes[static_cast<std::size_t>(new_nyt)] = AdaptiveNode{old_nyt, -1, -1, 0, -2};
            sym_idx[sym] = new_leaf;
            nyt = new_nyt;
            nodes[static_cast<std::size_t>(old_nyt)].weight = 1;
            cur = nodes[static_cast<std::size_t>(old_nyt)].parent;
        }
        while (cur != -1) {
            int ldr = find_leader(cur);
            if (ldr != cur && !is_ancestor(ldr, cur)) {
                swap_subtrees(cur, ldr);
                cur = ldr;
            }
            ++nodes[static_cast<std::size_t>(cur)].weight;
            cur = nodes[static_cast<std::size_t>(cur)].parent;
        }
    }

    void emit_path(int idx, std::vector<uint8_t>& out) const {
        std::vector<uint8_t> rev;
        while (idx != root) {
            int p = nodes[static_cast<std::size_t>(idx)].parent;
            rev.push_back(nodes[static_cast<std::size_t>(p)].right == idx ? 1 : 0);
            idx = p;
        }
        for (auto it = rev.rbegin(); it != rev.rend(); ++it) out.push_back(*it);
    }
};
} // namespace

EncodedStream adaptive_encode(const std::vector<uint8_t>& input) {
    EncodedStream s;
    s.orig_len = input.size();
    DynTree tree;
    for (uint8_t b : input) {
        int idx = tree.sym_idx[b];
        if (idx >= 0) {
            tree.emit_path(idx, s.bits);
        } else {
            tree.emit_path(tree.nyt, s.bits);
            for (int bit = 7; bit >= 0; --bit) s.bits.push_back((b >> bit) & 1U);
        }
        tree.update(b);
    }
    return s;
}

std::vector<uint8_t> adaptive_decode(const EncodedStream& stream) {
    std::vector<uint8_t> out;
    out.reserve(stream.orig_len);
    DynTree tree;
    std::size_t pos = 0;
    for (std::size_t i = 0; i < stream.orig_len; ++i) {
        int cur = tree.root;
        while (tree.nodes[static_cast<std::size_t>(cur)].left != -1 || tree.nodes[static_cast<std::size_t>(cur)].right != -1) {
            uint8_t bit = (pos < stream.bits.size()) ? stream.bits[pos++] : 0;
            cur = bit ? tree.nodes[static_cast<std::size_t>(cur)].right : tree.nodes[static_cast<std::size_t>(cur)].left;
        }
        uint8_t sym = 0;
        if (tree.nodes[static_cast<std::size_t>(cur)].symbol == -2) {
            for (int b = 0; b < 8; ++b) {
                sym = static_cast<uint8_t>((sym << 1U) | (pos < stream.bits.size() ? stream.bits[pos++] : 0));
            }
        } else {
            sym = static_cast<uint8_t>(tree.nodes[static_cast<std::size_t>(cur)].symbol);
        }
        out.push_back(sym);
        tree.update(sym);
    }
    return out;
}
} // namespace codes_huffman_adaptive_vitter
