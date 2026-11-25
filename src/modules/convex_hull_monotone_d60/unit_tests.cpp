#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_convex_hull_monotone_d60;
    validate_problem_size(1);
    auto h = convex_hull_ccw({{0,0},{4,0},{4,4},{0,4},{2,2},{1,3}});
    assert(h.size() == 4 && polygon_area2x(h) == 32);
    verify_module_postcondition(true, "unit ok");
    return 0;
}
