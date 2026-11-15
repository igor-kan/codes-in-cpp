#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include <string>
#include <array>
#include <functional>
#include <utility>

namespace codes_delaunay_bowyer_watson {
struct Pt2 {
    double x = 0.0;
    double y = 0.0;
};

struct Tri {
    std::size_t a = 0;
    std::size_t b = 0;
    std::size_t c = 0;
};
} // namespace codes_delaunay_bowyer_watson
