#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_coin_change_ways_d57;
    validate_problem_size(1);
    assert(count_coin_combinations({1, 2, 5}, 5) == 4);
    assert(count_coin_combinations({2}, 3) == 0);
    verify_module_postcondition(true, "unit ok");
    return 0;
}
