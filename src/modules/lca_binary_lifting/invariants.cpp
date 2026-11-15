#include "interface.hpp"

namespace codes_lca_binary_lifting {
Status verify_lca_properties(const LcaIndex& idx, std::size_t u, std::size_t v) {
    std::size_t l = query_lca(idx, u, v);
    if (!is_ancestor(idx, l, u) || !is_ancestor(idx, l, v)) return Status::InvariantViolation;
    if (l != idx.root && is_ancestor(idx, idx.up[l], u) == false) return Status::InvariantViolation;
    return Status::Ok;
}
} // namespace codes_lca_binary_lifting
