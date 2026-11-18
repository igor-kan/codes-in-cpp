#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_knuth_yao_quadrangle_dp;
    validate_problem_size(1);
    auto res = solve_obst_knuth({34, 8, 50});
    assert(res.min_cost == 142 && res.root_idx == 2);
    verify_module_postcondition(true, "unit ok");
    return 0;
}
