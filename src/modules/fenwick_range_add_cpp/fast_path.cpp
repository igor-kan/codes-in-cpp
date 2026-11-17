#include "interface.hpp"

namespace codes_fenwick_range_add_cpp {
void fast_apply_batch(DualFenwick& df, const std::vector<RangeAddOp>& ops) {
    for (const auto& op : ops) df.range_add(op.l, op.r, op.delta);
}
} // namespace codes_fenwick_range_add_cpp
