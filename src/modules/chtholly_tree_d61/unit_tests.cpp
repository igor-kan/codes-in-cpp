#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_chtholly_tree_d61;
    validate_problem_size(1);
    ChthollyTree ct(10);
    assert(ct.range_sum(0, 9) == 0);
    ct.assign(2, 5, 7);
    assert(ct.range_sum(0, 9) == 28);
    ct.assign(4, 6, 1);
    assert(ct.range_sum(0, 9) == 17);
    assert(ct.range_sum(4, 6) == 3);
    assert(ct.interval_count() == 4);
    verify_module_postcondition(true, "unit ok");
    return 0;
}
