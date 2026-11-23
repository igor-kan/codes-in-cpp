#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_graham_scan_hull_d58;
    validate_problem_size(1);
    assert(convex_hull_area2({{0,0},{4,0},{4,3},{0,3},{2,1}}) == 24);
    verify_module_postcondition(true, "unit ok");
    return 0;
}
