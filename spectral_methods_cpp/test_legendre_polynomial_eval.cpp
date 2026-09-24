#include "legendre_polynomial_eval.hpp"
#include <cassert>
#include <iostream>

int main() {
    assert(legendre_p(0, 0.5) == 1.0); assert(legendre_p(1, 0.5) == 0.5);
    std::cout << "test_legendre_polynomial_eval.cpp passed.\n";
    return 0;
}
