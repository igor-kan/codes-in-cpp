#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_heavy_light_path_d60;
    validate_problem_size(1);
    TreeLcaSolver tr(5, {{0,1,3},{0,2,4},{1,3,5},{1,4,2}});
    assert(tr.lca(3, 4) == 1);
    assert(tr.path_dist(3, 2) == 12);
    verify_module_postcondition(true, "unit ok");
    return 0;
}
