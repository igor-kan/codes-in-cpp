#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include <string>
#include <array>
#include <functional>
#include <utility>

namespace codes_fenwick_range_add_cpp {
struct RangeAddOp {
    int l;
    int r;
    std::int64_t delta;
};
} // namespace codes_fenwick_range_add_cpp
