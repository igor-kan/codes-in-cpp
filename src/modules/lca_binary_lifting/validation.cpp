#include "interface.hpp"

namespace codes_lca_binary_lifting {
Status validate_tree_edges(std::size_t n, const std::vector<std::pair<std::size_t, std::size_t>>& edges) {
    if (n == 0) return Status::NullOrEmpty;
    if (edges.size() != n - 1) return Status::InvalidInput;
    for (const auto& e : edges) {
        if (e.first >= n || e.second >= n || e.first == e.second) return Status::OutOfBounds;
    }
    return Status::Ok;
}
} // namespace codes_lca_binary_lifting
