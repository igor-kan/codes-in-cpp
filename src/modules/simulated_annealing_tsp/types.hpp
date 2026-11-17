#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include <string>
#include <array>
#include <functional>
#include <utility>

namespace codes_simulated_annealing_tsp {
struct Point2D {
    double x;
    double y;
};

struct TspResult {
    std::vector<int> tour;
    double total_length;
};
} // namespace codes_simulated_annealing_tsp
