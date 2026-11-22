#pragma once
#include "types.hpp"
#include "errors.hpp"

namespace codes_seg_tree_max_sub_d57 {
class MaxSubSegTree {
public:
    explicit MaxSubSegTree(const std::vector<long long>& xs);
    void update(int pos, long long val);
    long long query_best(int ql, int qr) const;
private:
    int n_;
    std::vector<MaxSubNode> t_;
    static MaxSubNode combine(const MaxSubNode& l, const MaxSubNode& r);
    void set_rec(int node, int l, int r, int pos, long long v);
    MaxSubNode query_rec(int node, int l, int r, int ql, int qr) const;
};

void validate_problem_size(int n);
std::int64_t fast_checksum_span(const std::vector<std::int64_t>& xs);
std::vector<std::int64_t> parallel_checksum_batches(const std::vector<std::vector<std::int64_t>>& batches);
void verify_module_postcondition(bool ok, const char* msg);
} // namespace codes_seg_tree_max_sub_d57
