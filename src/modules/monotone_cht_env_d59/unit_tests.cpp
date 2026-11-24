#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_monotone_cht_env_d59;
    validate_problem_size(1);
    MonotoneCht ch;
    ch.add_decreasing(5, 10);
    ch.add_decreasing(2, 20);
    ch.add_decreasing(-1, 50);
    assert(ch.query_increasing(1) == 15 && ch.query_increasing(5) == 30 && ch.query_increasing(12) == 38);
    verify_module_postcondition(true, "unit ok");
    return 0;
}
