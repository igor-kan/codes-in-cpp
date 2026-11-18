#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include <string>
#include <array>
#include <functional>
#include <utility>

namespace codes_fractional_cascading_grid {
struct FcEntry {
    std::int64_t key;
    int real_idx;
    int next_idx;
};

struct ModuleMeta {
    static constexpr const char* kSlug = "fractional_cascading_grid";
    int version = 1;
};
} // namespace codes_fractional_cascading_grid
