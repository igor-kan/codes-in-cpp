#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_hungarian_min_assign_cpp;
    validate_problem_size(1);
    auto r = hungarian_min_cost({{1, 2, 3}, {2, 4, 6}, {3, 6, 9}});
    assert(r.total_cost == 10);
    verify_module_postcondition(true, "unit ok");
    return 0;
}
