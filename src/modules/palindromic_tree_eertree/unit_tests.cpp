#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_palindromic_tree_eertree;
    validate_problem_size(1);
    Eertree et("ertre");
    assert(et.distinct_palindromes() == 5);
    assert(et.max_palindrome_length() == 5);
    verify_module_postcondition(true, "unit ok");
    return 0;
}
