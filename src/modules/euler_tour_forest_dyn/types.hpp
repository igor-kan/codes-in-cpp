#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include <string>
#include <array>
#include <functional>
#include <utility>

namespace codes_euler_tour_forest_dyn {
struct EulerRange {
    int tin = 0;
    int tout = 0;
};

struct ModuleMeta {
    static constexpr const char* kSlug = "euler_tour_forest_dyn";
    int version = 1;
};
} // namespace codes_euler_tour_forest_dyn
