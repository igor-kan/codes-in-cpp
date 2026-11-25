#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_manacher_pal_d60;
    validate_problem_size(1);
    auto p = longest_palindrome_d60("babad");
    assert(p.length == 3);
    auto p2 = longest_palindrome_d60("cbbd");
    assert(p2.length == 2 && p2.start == 1);
    verify_module_postcondition(true, "unit ok");
    return 0;
}
