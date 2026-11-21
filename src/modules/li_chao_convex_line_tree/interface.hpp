#pragma once
#include "types.hpp"
#include "errors.hpp"

namespace codes_li_chao_convex_line_tree {
class LiChaoTree {
public:
    explicit LiChaoTree(int max_x);
    void add_line(long long m, long long b);
    long long query(int x) const;
private:
    int max_x_;
    std::vector<LinearFn> tree_;
    void insert(int node, int l, int r, LinearFn fn);
    long long query_rec(int node, int l, int r, int x) const;
};

void validate_problem_size(int n);
std::int64_t fast_checksum_span(const std::vector<std::int64_t>& xs);
std::vector<std::int64_t> parallel_checksum_batches(const std::vector<std::vector<std::int64_t>>& batches);
void verify_module_postcondition(bool ok, const char* msg);
} // namespace codes_li_chao_convex_line_tree
