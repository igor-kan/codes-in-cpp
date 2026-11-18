#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include <string>
#include <array>
#include <functional>
#include <utility>

namespace codes_knuth_yao_quadrangle_dp {
struct ObstResult {
    std::int64_t min_cost = 0;
    int root_idx = -1;
};

struct ModuleMeta {
    static constexpr const char* kSlug = "knuth_yao_quadrangle_dp";
    int version = 1;
};
} // namespace codes_knuth_yao_quadrangle_dp
