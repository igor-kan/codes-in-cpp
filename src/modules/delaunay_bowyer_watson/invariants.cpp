#include "interface.hpp"

namespace codes_delaunay_bowyer_watson {
Status verify_empty_circumcircles(const std::vector<Pt2>& pts, const std::vector<Tri>& tris) {
    for (const auto& t : tris) {
        if (tri_orient2d(pts[t.a], pts[t.b], pts[t.c]) <= 1e-12) return Status::InvariantViolation;
        for (std::size_t k = 0; k < pts.size(); ++k) {
            if (k == t.a || k == t.b || k == t.c) continue;
            if (point_in_circumcircle(pts[t.a], pts[t.b], pts[t.c], pts[k])) {
                return Status::InvariantViolation;
            }
        }
    }
    return Status::Ok;
}
} // namespace codes_delaunay_bowyer_watson
