#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_segment_lazy_add_d60;
    validate_problem_size(1);
    LazySegTree seg(10);
    seg.range_add(1, 5, 3);
    seg.range_add(3, 8, 2);
    assert(seg.range_sum(1, 5) == 21);
    assert(seg.range_sum(0, 9) == 27);
    verify_module_postcondition(true, "unit ok");
    return 0;
}
