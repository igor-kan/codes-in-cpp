#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_delaunay_bowyer_watson;
    // Unit square + slightly off-center interior point (avoids 4-cocircular tie)
    std::vector<Pt2> pts = {{0.0, 0.0}, {4.0, 0.0}, {4.0, 3.0}, {0.0, 3.0}, {1.7, 1.4}};
    assert(validate_points_distinct(pts) == Status::Ok);
    auto tris = bowyer_watson_triangulate(pts);
    assert(tris.size() == 4);
    assert(std::abs(triangulation_total_area(pts, tris) - 12.0) < 1e-9);
    assert(verify_empty_circumcircles(pts, tris) == Status::Ok);
    return 0;
}
