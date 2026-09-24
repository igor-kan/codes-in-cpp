#include "lu_decomposition_doolittle.hpp"
#include <cassert>
#include <iostream>

int main() {
    assert(doolittle_multiplier(4.0, 2.0) == 2.0);
    std::cout << "test_lu_decomposition_doolittle.cpp passed.\n";
    return 0;
}
