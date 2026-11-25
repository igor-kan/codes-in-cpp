#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include <string>
#include <array>
#include <functional>
#include <utility>

namespace codes_convex_hull_monotone_d60 {
struct Pt2D {
    std::int64_t x;
    std::int64_t y;
    bool operator<(const Pt2D& o) const { return x < o.x || (x == o.x && y < o.y); }
    bool operator==(const Pt2D& o) const { return x == o.x && y == o.y; }
};

struct ModuleMeta {
    static constexpr const char* kSlug = "convex_hull_monotone_d60";
    int version = 1;
};
} // namespace codes_convex_hull_monotone_d60
