#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_seg_tree_max_sub_d57;
    validate_problem_size(1);
    MaxSubSegTree st({-2, 1, -3, 4, -1, 2, 1, -5, 4});
    assert(st.query_best(0, 8) == 6);
    st.update(4, 3);
    assert(st.query_best(3, 6) == 10);
    verify_module_postcondition(true, "unit ok");
    return 0;
}
