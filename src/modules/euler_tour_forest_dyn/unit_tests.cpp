#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_euler_tour_forest_dyn;
    validate_problem_size(1);
    EulerSubtreeIndex et(5, 0, {{0,1},{0,2},{1,3},{1,4}}, {10, 20, 30, 40, 50});
    assert(et.query_subtree_sum(1) == 110);
    et.add_vertex_weight(3, 5);
    assert(et.query_subtree_sum(1) == 115 && et.query_subtree_sum(0) == 155);
    verify_module_postcondition(true, "unit ok");
    return 0;
}
