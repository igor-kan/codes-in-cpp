#pragma once
#include "types.hpp"
#include "errors.hpp"

namespace codes_segment_lazy_add_d60 {
class LazySegTree {
    int n_;
    std::vector<std::int64_t> sum_;
    std::vector<std::int64_t> lazy_;
    void push(int idx, int l, int r);
    void add_rec(int idx, int l, int r, int ql, int qr, std::int64_t v);
    std::int64_t sum_rec(int idx, int l, int r, int ql, int qr);
public:
    explicit LazySegTree(int n);
    void range_add(int l, int r, std::int64_t v);
    std::int64_t range_sum(int l, int r);
};

void validate_problem_size(int n);
std::int64_t fast_checksum_span(const std::vector<std::int64_t>& xs);
std::vector<std::int64_t> parallel_checksum_batches(const std::vector<std::vector<std::int64_t>>& batches);
void verify_module_postcondition(bool ok, const char* msg);
} // namespace codes_segment_lazy_add_d60
