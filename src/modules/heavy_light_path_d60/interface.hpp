#pragma once
#include "types.hpp"
#include "errors.hpp"

namespace codes_heavy_light_path_d60 {
class TreeLcaSolver {
    int n_, logk_;
    std::vector<int> dep_;
    std::vector<std::int64_t> dist_;
    std::vector<std::vector<int>> up_;
public:
    TreeLcaSolver(int n, const std::vector<TreeEdge>& edges);
    int lca(int u, int v) const;
    std::int64_t path_dist(int u, int v) const;
};

void validate_problem_size(int n);
std::int64_t fast_checksum_span(const std::vector<std::int64_t>& xs);
std::vector<std::int64_t> parallel_checksum_batches(const std::vector<std::vector<std::int64_t>>& batches);
void verify_module_postcondition(bool ok, const char* msg);
} // namespace codes_heavy_light_path_d60
