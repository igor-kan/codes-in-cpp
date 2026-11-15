#include "interface.hpp"

namespace codes_persistent_seg_tree {
Status verify_pst_node_sums(const PersistentSegTree& pst, int node, std::size_t l, std::size_t r) {
    if (node < 0 || static_cast<std::size_t>(node) >= pst.pool.size()) return Status::InvariantViolation;
    if (l == r) return Status::Ok;
    const PstNode& n = pst.pool[static_cast<std::size_t>(node)];
    if (n.left < 0 || n.right < 0) return Status::InvariantViolation;
    if (n.sum != pst.pool[static_cast<std::size_t>(n.left)].sum + pst.pool[static_cast<std::size_t>(n.right)].sum) {
        return Status::InvariantViolation;
    }
    std::size_t m = l + (r - l) / 2;
    if (verify_pst_node_sums(pst, n.left, l, m) != Status::Ok) return Status::InvariantViolation;
    return verify_pst_node_sums(pst, n.right, m + 1, r);
}
} // namespace codes_persistent_seg_tree
