#pragma once
#include "types.hpp"
#include "errors.hpp"

namespace codes_euler_tour_forest_dyn {
class EulerSubtreeIndex {
public:
    EulerSubtreeIndex(int n, int root, const std::vector<std::pair<int, int>>& edges, const std::vector<std::int64_t>& init_w);
    void add_vertex_weight(int u, std::int64_t delta);
    std::int64_t query_subtree_sum(int u) const;
private:
    int n_;
    std::vector<EulerRange> range_;
    std::vector<std::int64_t> bit_;
    void bit_add(int idx, std::int64_t delta);
    std::int64_t bit_sum(int idx) const;
};

void validate_problem_size(int n);
std::int64_t fast_checksum_span(const std::vector<std::int64_t>& xs);
std::vector<std::int64_t> parallel_checksum_batches(const std::vector<std::vector<std::int64_t>>& batches);
void verify_module_postcondition(bool ok, const char* msg);
} // namespace codes_euler_tour_forest_dyn
