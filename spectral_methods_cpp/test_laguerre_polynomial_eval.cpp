#include "laguerre_polynomial_eval.hpp"
#include <cassert>
#include <iostream>

int main() {
    assert(laguerre_l(0, 2.0) == 1.0); assert(laguerre_l(1, 2.0) == -1.0);
    std::cout << "test_laguerre_polynomial_eval.cpp passed.\n";
    return 0;
}
