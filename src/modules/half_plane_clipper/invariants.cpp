#include "interface.hpp"

namespace codes_half_plane_clipper {
Status verify_convex_left_region(const std::vector<HalfPlane>& planes, const std::vector<Vec2>& poly) {
    for (const auto& v : poly) {
        if (!point_inside_all(planes, v, 1e-6)) return Status::InvariantViolation;
    }
    if (poly.size() >= 3 && polygon_area(poly) < -1e-9) return Status::InvariantViolation;
    return Status::Ok;
}
} // namespace codes_half_plane_clipper
