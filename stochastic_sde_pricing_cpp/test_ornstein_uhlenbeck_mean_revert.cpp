#include "ornstein_uhlenbeck_mean_revert.hpp"
#include <cassert>
#include <iostream>

int main() {
    assert(std::abs(ou_expectation(10.0, 1.0, 2.0, 0.0) - 10.0) < 1e-7);
    std::cout << "test_ornstein_uhlenbeck_mean_revert.cpp passed.\n";
    return 0;
}
