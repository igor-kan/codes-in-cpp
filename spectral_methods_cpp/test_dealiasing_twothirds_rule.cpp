#include "dealiasing_twothirds_rule.hpp"
#include <cassert>
#include <iostream>

int main() {
    assert(is_aliased(12, 32) == true); assert(is_aliased(5, 32) == false);
    std::cout << "test_dealiasing_twothirds_rule.cpp passed.\n";
    return 0;
}
