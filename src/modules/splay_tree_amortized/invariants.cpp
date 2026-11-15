#include "interface.hpp"

namespace codes_splay_tree_amortized {
Status verify_splay_bst(const SplayTree& tree, int x, long long lo, long long hi) {
    if (x < 0) return Status::Ok;
    const SplayNode& n = tree.pool[static_cast<std::size_t>(x)];
    if (n.key <= lo || n.key >= hi) return Status::InvariantViolation;
    std::size_t exp_sz = 1;
    if (n.ch[0] >= 0) {
        if (tree.pool[static_cast<std::size_t>(n.ch[0])].parent != x) return Status::InvariantViolation;
        exp_sz += tree.pool[static_cast<std::size_t>(n.ch[0])].sz;
        if (verify_splay_bst(tree, n.ch[0], lo, n.key) != Status::Ok) return Status::InvariantViolation;
    }
    if (n.ch[1] >= 0) {
        if (tree.pool[static_cast<std::size_t>(n.ch[1])].parent != x) return Status::InvariantViolation;
        exp_sz += tree.pool[static_cast<std::size_t>(n.ch[1])].sz;
        if (verify_splay_bst(tree, n.ch[1], n.key, hi) != Status::Ok) return Status::InvariantViolation;
    }
    if (n.sz != exp_sz) return Status::InvariantViolation;
    return Status::Ok;
}
} // namespace codes_splay_tree_amortized
