#include "jacobi_diagonalization_symm.hpp"
#include <cassert>
#include <iostream>

int main() {
    assert(std::abs(jacobi_theta(1.0, 1.0, 1.0) - M_PI/4.0) < 1e-7);
    std::cout << "test_jacobi_diagonalization_symm.cpp passed.\n";
    return 0;
}
