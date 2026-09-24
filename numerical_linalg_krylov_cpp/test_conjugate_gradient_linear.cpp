#include "conjugate_gradient_linear.hpp"
#include <cassert>
#include <iostream>

int main() {
    assert(cg_beta(0.5, 2.0) == 0.25);
    std::cout << "test_conjugate_gradient_linear.cpp passed.\n";
    return 0;
}
