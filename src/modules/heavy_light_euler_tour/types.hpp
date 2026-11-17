#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include <string>
#include <array>
#include <functional>
#include <utility>

namespace codes_heavy_light_euler_tour {
struct EulerIndex {
    std::vector<int> tin;
    std::vector<int> tout;
    std::vector<int> order;
};
} // namespace codes_heavy_light_euler_tour
