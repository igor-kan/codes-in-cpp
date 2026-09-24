#include "hermite_polynomial_eval.hpp"
#include <cassert>
#include <iostream>

int main() {
    assert(hermite_h(0, 1.0) == 1.0); assert(hermite_h(1, 1.0) == 2.0);
    std::cout << "test_hermite_polynomial_eval.cpp passed.\n";
    return 0;
}
