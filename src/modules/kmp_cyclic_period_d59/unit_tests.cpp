#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_kmp_cyclic_period_d59;
    validate_problem_size(1);
    assert(shortest_exact_period("ababab") == 2);
    assert(shortest_exact_period("abcab") == 5);
    verify_module_postcondition(true, "unit ok");
    return 0;
}
