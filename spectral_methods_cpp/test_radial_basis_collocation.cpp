#include "radial_basis_collocation.hpp"
#include <cassert>
#include <iostream>

int main() {
    assert(gaussian_rbf(0.0, 1.0) == 1.0);
    std::cout << "test_radial_basis_collocation.cpp passed.\n";
    return 0;
}
