#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_johnsons_reweight_apsp;
    validate_problem_size(1);
    auto d = johnson_apsp(4, {{0,1,4},{0,2,5},{1,2,-3},{2,3,2}});
    assert(d[0][3] == 3 && d[1][3] == -1);
    verify_module_postcondition(true, "unit ok");
    return 0;
}
