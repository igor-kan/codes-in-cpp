#include "chebyshev_lobatto_quadrature.hpp"
#include <cassert>
#include <iostream>

int main() {
    assert(cl_weights_sum(10) == 2.0);
    std::cout << "test_chebyshev_lobatto_quadrature.cpp passed.\n";
    return 0;
}
