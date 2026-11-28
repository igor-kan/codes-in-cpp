#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_segment_lazy_mul_add_d61;
    validate_problem_size(1);
    std::vector<std::int64_t> a = {1, 2, 3, 4, 5};
    LazyMulAddTree seg(a);
    seg.range_add(1, 3, 10);
    assert(seg.range_sum(0, 4) == 45);
    seg.range_mul(0, 4, 2);
    assert(seg.range_sum(0, 4) == 90);
    assert(seg.range_sum(0, 0) == 2);
    assert(seg.range_sum(1, 3) == 78);
    verify_module_postcondition(true, "unit ok");
    return 0;
}
