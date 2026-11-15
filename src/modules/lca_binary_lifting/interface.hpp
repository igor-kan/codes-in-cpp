#pragma once
#include "types.hpp"
#include "errors.hpp"

namespace codes_lca_binary_lifting {
LcaIndex build_lca(std::size_t n, const std::vector<std::pair<std::size_t, std::size_t>>& edges, std::size_t root);
bool is_ancestor(const LcaIndex& idx, std::size_t u, std::size_t v);
std::size_t query_lca(const LcaIndex& idx, std::size_t u, std::size_t v);
std::size_t tree_distance(const LcaIndex& idx, std::size_t u, std::size_t v);
Status validate_tree_edges(std::size_t n, const std::vector<std::pair<std::size_t, std::size_t>>& edges);
std::size_t kth_ancestor(const LcaIndex& idx, std::size_t u, std::size_t k);
std::vector<std::size_t> parallel_lca_batch(const LcaIndex& idx, const std::vector<std::pair<std::size_t, std::size_t>>& pairs);
Status verify_lca_properties(const LcaIndex& idx, std::size_t u, std::size_t v);
} // namespace codes_lca_binary_lifting
