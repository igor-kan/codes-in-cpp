#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_delaunay_bowyer_watson;
    // Spiral general-position point cloud
    std::vector<Pt2> pts;
    for (int i = 0; i < 18; ++i) {
        double r = 1.0 + 0.4 * i;
        double ang = i * 2.399963229728653; // golden angle
        pts.push_back({r * std::cos(ang), r * std::sin(ang)});
    }
    auto tris = bowyer_watson_triangulate(pts);
    assert(!tris.empty());
    assert(verify_empty_circumcircles(pts, tris) == Status::Ok);
    return 0;
}
