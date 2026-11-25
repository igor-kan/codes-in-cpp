#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include <string>
#include <array>
#include <functional>
#include <utility>

namespace codes_segment_lazy_add_d60 {
struct RangeOp {
    int l;
    int r;
    std::int64_t val;
};

struct ModuleMeta {
    static constexpr const char* kSlug = "segment_lazy_add_d60";
    int version = 1;
};
} // namespace codes_segment_lazy_add_d60
