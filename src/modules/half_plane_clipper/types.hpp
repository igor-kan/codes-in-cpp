#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include <string>
#include <array>
#include <functional>
#include <utility>

namespace codes_half_plane_clipper {
struct Vec2 {
    double x = 0.0;
    double y = 0.0;
};

struct HalfPlane {
    Vec2 p;   // point on boundary
    Vec2 dir; // direction vector; feasible region lies to its left (cross(dir, q - p) >= 0)
};
} // namespace codes_half_plane_clipper
