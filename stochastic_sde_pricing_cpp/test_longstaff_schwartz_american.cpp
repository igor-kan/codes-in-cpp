#include "longstaff_schwartz_american.hpp"
#include <cassert>
#include <iostream>

int main() {
    assert(continuation_value(1.0, 0.5, 10.0) == 6.0);
    std::cout << "test_longstaff_schwartz_american.cpp passed.\n";
    return 0;
}
