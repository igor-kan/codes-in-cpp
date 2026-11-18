#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include <string>
#include <array>
#include <functional>
#include <utility>

namespace codes_golden_section_convex_opt {
struct Minima1D {
    double x = 0.0;
    double fx = 0.0;
    int iterations = 0;
};

struct ModuleMeta {
    static constexpr const char* kSlug = "golden_section_convex_opt";
    int version = 1;
};
} // namespace codes_golden_section_convex_opt
