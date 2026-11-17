#pragma once
#include "types.hpp"
#include "errors.hpp"

namespace codes_fenwick_range_add_cpp {
class DualFenwick {
public:
    explicit DualFenwick(int n);
    void range_add(int l, int r, std::int64_t delta);
    std::int64_t prefix_sum(int idx) const;
    std::int64_t range_sum(int l, int r) const;
    int size() const { return n_; }

private:
    int n_;
    std::vector<std::int64_t> b1_;
    std::vector<std::int64_t> b2_;
    void add_bit(std::vector<std::int64_t>& bit, int pos, std::int64_t val);
    std::int64_t query_bit(const std::vector<std::int64_t>& bit, int pos) const;
};

void validate_interval(int n, int l, int r);
void fast_apply_batch(DualFenwick& df, const std::vector<RangeAddOp>& ops);
std::vector<std::int64_t> parallel_verify_shards(int n, const std::vector<std::vector<RangeAddOp>>& shards);
void verify_dual_fenwick_oracle(int n, const std::vector<RangeAddOp>& ops);
} // namespace codes_fenwick_range_add_cpp
