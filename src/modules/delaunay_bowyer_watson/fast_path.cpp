#include "interface.hpp"
#include <cmath>

namespace codes_delaunay_bowyer_watson {
double triangulation_total_area(const std::vector<Pt2>& pts, const std::vector<Tri>& tris) {
    double sum = 0.0;
    for (const auto& t : tris) {
        sum += std::abs(tri_orient2d(pts[t.a], pts[t.b], pts[t.c])) * 0.5;
    }
    return sum;
}
} // namespace codes_delaunay_bowyer_watson
