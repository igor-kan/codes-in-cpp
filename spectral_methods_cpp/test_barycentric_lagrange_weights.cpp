#include "barycentric_lagrange_weights.hpp"
#include <cassert>
#include <iostream>

int main() {
    assert(cheb_weight(0, 4) == 0.5);
    std::cout << "test_barycentric_lagrange_weights.cpp passed.\n";
    return 0;
}
