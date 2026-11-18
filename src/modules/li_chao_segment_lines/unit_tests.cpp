#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_li_chao_segment_lines;
    validate_problem_size(1);
    LiChaoTree lc(100);
    lc.add_line(2, 10);
    lc.add_line(-1, 50);
    lc.add_line(0, 25);
    assert(lc.query(5) == 20 && lc.query(15) == 25 && lc.query(40) == 10);
    verify_module_postcondition(true, "unit ok");
    return 0;
}
