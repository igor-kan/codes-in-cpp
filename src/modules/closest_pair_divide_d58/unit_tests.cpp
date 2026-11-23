#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_closest_pair_divide_d58;
    validate_problem_size(1);
    assert(closest_pair_dist2({{2,3},{12,30},{40,50},{5,1},{12,10},{3,4}}) == 2);
    verify_module_postcondition(true, "unit ok");
    return 0;
}
