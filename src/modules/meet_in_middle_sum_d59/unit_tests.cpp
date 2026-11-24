#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_meet_in_middle_sum_d59;
    validate_problem_size(1);
    assert(subset_sum_mim({3, 34, 4, 12, 5, 2}, 9));
    assert(!subset_sum_mim({3, 34, 4, 12, 5, 2}, 30));
    verify_module_postcondition(true, "unit ok");
    return 0;
}
