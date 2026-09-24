#include "rayleigh_quotient_iteration.hpp"
#include <cassert>
#include <iostream>

int main() {
    assert(shifted_eigenvalue(2.0, 0.5) == 2.5);
    std::cout << "test_rayleigh_quotient_iteration.cpp passed.\n";
    return 0;
}
