#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_monotonic_stack_histogram;
    validate_problem_size(1);
    assert(largest_histogram_area({2, 1, 5, 6, 2, 3}) == 10);
    assert(largest_histogram_area({2, 4}) == 4);
    verify_module_postcondition(true, "unit ok");
    return 0;
}
