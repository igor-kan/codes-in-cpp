#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_li_chao_convex_line_tree;
    validate_problem_size(1);
    LiChaoTree lc(64);
    lc.add_line(2, 5);
    lc.add_line(-1, 20);
    lc.add_line(0, 12);
    assert(lc.query(0) == 5 && lc.query(5) == 12 && lc.query(15) == 5);
    verify_module_postcondition(true, "unit ok");
    return 0;
}
