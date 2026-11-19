#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_convex_hull_trick_deque;
    validate_problem_size(1);
    MonotoneCht cht;
    cht.add_line(3, 0); cht.add_line(2, 4); cht.add_line(0, 14);
    assert(cht.query(1) == 3 && cht.query(5) == 14 && cht.query(10) == 14);
    verify_module_postcondition(true, "unit ok");
    return 0;
}
