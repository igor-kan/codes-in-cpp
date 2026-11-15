#include "interface.hpp"

namespace codes_half_plane_clipper {
bool point_inside_all(const std::vector<HalfPlane>& planes, Vec2 q, double eps) {
    for (const auto& hp : planes) {
        double c = hp.dir.x * (q.y - hp.p.y) - hp.dir.y * (q.x - hp.p.x);
        if (c < -eps) return false;
    }
    return true;
}
} // namespace codes_half_plane_clipper
