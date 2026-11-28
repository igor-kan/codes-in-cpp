#pragma once
#include "types.hpp"
#include "errors.hpp"

namespace codes_segment_lazy_mul_add_d61 {
class LazyMulAddTree {
public:
    explicit LazyMulAddTree(const std::vector<std::int64_t>& a);
    void range_add(int l, int r, std::int64_t v);
    void range_mul(int l, int r, std::int64_t v);
    std::int64_t range_sum(int l, int r);
private:
    int n_ = 0;
    std::vector<std::int64_t> sum_;
    std::vector<std::int64_t> add_;
    std::vector<std::int64_t> mul_;
    void build(int idx, int l, int r, const std::vector<std::int64_t>& a);
    void apply(int idx, int len, std::int64_t m, std::int64_t a);
    void push(int idx, int l, int r);
    void pull(int idx);
    void update(int idx, int l, int r, int ql, int qr, std::int64_t m, std::int64_t a);
    std::int64_t query(int idx, int l, int r, int ql, int qr);
};

void validate_problem_size(int n);
std::int64_t fast_checksum_span(const std::vector<std::int64_t>& xs);
std::vector<std::int64_t> parallel_checksum_batches(const std::vector<std::vector<std::int64_t>>& batches);
void verify_module_postcondition(bool ok, const char* msg);
} // namespace codes_segment_lazy_mul_add_d61
