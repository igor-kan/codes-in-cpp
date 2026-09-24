#include "tridiagonal_thomas_algorithm.hpp"
#include <cassert>
#include <iostream>

int main() {
    assert(thomas_c_prime(2.0, 4.0, 0.0, 0.0) == 0.5);
    std::cout << "test_tridiagonal_thomas_algorithm.cpp passed.\n";
    return 0;
}
