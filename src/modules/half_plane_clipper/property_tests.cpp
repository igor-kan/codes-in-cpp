#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_half_plane_clipper;
    // Regular N-gon half-planes tangent to unit circle have area N * tan(pi/N)
    const double pi = std::acos(-1.0);
    for (int sides : {6, 8, 12, 24}) {
        std::vector<HalfPlane> hps;
        for (int k = 0; k < sides; ++k) {
            double ang = 2.0 * pi * k / sides;
            Vec2 p = {std::cos(ang), std::sin(ang)};
            Vec2 d = {-std::sin(ang), std::cos(ang)}; // tangent CCW -> origin is to left
            hps.push_back({p, d});
        }
        auto poly = intersect_half_planes(hps);
        double expected = sides * std::tan(pi / sides);
        assert(std::abs(polygon_area(poly) - expected) < 1e-5);
        assert(verify_convex_left_region(hps, poly) == Status::Ok);
    }
    return 0;
}
