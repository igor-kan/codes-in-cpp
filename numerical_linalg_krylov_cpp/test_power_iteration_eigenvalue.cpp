#include "power_iteration_eigenvalue.hpp"
#include <cassert>
#include <iostream>

int main() {
    assert(rayleigh_quotient(12.0, 3.0) == 4.0);
    std::cout << "test_power_iteration_eigenvalue.cpp passed.\n";
    return 0;
}
