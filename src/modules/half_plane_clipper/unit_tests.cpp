#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_half_plane_clipper;
    // Unit square [0, 4] x [0, 3] cut by x + y <= 4 -> corner (4,3) clipped to polygon of area 12 - 0.5*3*3 = 7.5? Wait:
    // x + y <= 4 intercepts x=4 at y=0, y=3 at x=1! Triangle outside is (1,3)-(4,3)-(4,0) of area 0.5*3*3 = 4.5 -> remaining area = 12 - 4.5 = 7.5!
    std::vector<HalfPlane> hps = {
        {{0.0, 0.0}, {1.0, 0.0}},   // y >= 0
        {{4.0, 0.0}, {0.0, 1.0}},   // x <= 4
        {{4.0, 3.0}, {-1.0, 0.0}},  // y <= 3
        {{0.0, 3.0}, {0.0, -1.0}},  // x >= 0
        {{4.0, 0.0}, {-1.0, 1.0}}   // left of (4,0)->(0,4): x + y <= 4
    };
    auto poly = intersect_half_planes(hps);
    assert(poly.size() == 4);
    assert(std::abs(polygon_area(poly) - 7.5) < 1e-6);
    assert(verify_convex_left_region(hps, poly) == Status::Ok);
    // Infeasible pair: y >= 2 and y <= 1
    std::vector<HalfPlane> empty_hps = {{{0.0, 2.0}, {1.0, 0.0}}, {{0.0, 1.0}, {-1.0, 0.0}}};
    assert(intersect_half_planes(empty_hps).empty());
    return 0;
}
