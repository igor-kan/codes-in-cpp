#pragma once
#include "types.hpp"
#include "errors.hpp"

namespace codes_heavy_light_euler_tour {
class EulerSubtreeEngine {
public:
    EulerSubtreeEngine(int n, const std::vector<std::pair<int, int>>& edges, const std::vector<std::int64_t>& init);
    void add_point(int u, std::int64_t delta);
    std::int64_t subtree_sum(int u) const;
    const EulerIndex& tour() const { return idx_; }

private:
    int n_;
    EulerIndex idx_;
    std::vector<std::int64_t> bit_;
    void bit_add(int pos, std::int64_t v);
    std::int64_t bit_prefix(int pos) const;
};

void validate_rooted_tree(int n, const std::vector<std::pair<int, int>>& edges, const std::vector<std::int64_t>& init);
std::vector<std::int64_t> fast_batch_subtree_sums(const EulerSubtreeEngine& eng, const std::vector<int>& roots);
std::vector<std::int64_t> parallel_subtree_queries(int n, const std::vector<std::pair<int, int>>& edges,
                                                   const std::vector<std::int64_t>& init,
                                                   const std::vector<int>& queries);
void verify_euler_brackets(const EulerIndex& idx);
} // namespace codes_heavy_light_euler_tour
