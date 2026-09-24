#include "gauss_legendre_abscissas.hpp"
#include <cassert>
#include <iostream>

int main() {
    assert(gl_midpoint(-1.0, 1.0) == 0.0);
    std::cout << "test_gauss_legendre_abscissas.cpp passed.\n";
    return 0;
}
