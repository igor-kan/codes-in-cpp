#include "implied_volatility_bisection.hpp"
#include <cassert>
#include <iostream>

int main() {
    assert(bisection_mid(0.1, 0.3) == 0.2);
    std::cout << "test_implied_volatility_bisection.cpp passed.\n";
    return 0;
}
