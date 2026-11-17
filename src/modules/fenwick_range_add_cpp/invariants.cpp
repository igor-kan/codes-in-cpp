#include "interface.hpp"

namespace codes_fenwick_range_add_cpp {
void verify_dual_fenwick_oracle(int n, const std::vector<RangeAddOp>& ops) {
    DualFenwick df(n);
    std::vector<std::int64_t> ref(static_cast<std::size_t>(n), 0);
    for (const auto& op : ops) {
        df.range_add(op.l, op.r, op.delta);
        for (int i = op.l; i <= op.r; ++i) ref[static_cast<std::size_t>(i)] += op.delta;
    }
    for (int l = 0; l < n; ++l) {
        std::int64_t acc = 0;
        for (int r = l; r < n; ++r) {
            acc += ref[static_cast<std::size_t>(r)];
            if (df.range_sum(l, r) != acc) throw std::logic_error("dual Fenwick sum mismatch");
        }
    }
}
} // namespace codes_fenwick_range_add_cpp
