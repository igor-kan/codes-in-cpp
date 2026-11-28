#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include <string>
#include <array>
#include <functional>
#include <utility>

namespace codes_segment_lazy_mul_add_d61 {
struct AffineOp {
    std::int64_t mul;
    std::int64_t add;
};

struct ModuleMeta {
    static constexpr const char* kSlug = "segment_lazy_mul_add_d61";
    int version = 1;
};
} // namespace codes_segment_lazy_mul_add_d61
