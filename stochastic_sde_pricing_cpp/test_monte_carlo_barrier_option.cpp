#include "monte_carlo_barrier_option.hpp"
#include <cassert>
#include <iostream>

int main() {
    assert(is_knocked_out(125.0, 120.0) == true);
    std::cout << "test_monte_carlo_barrier_option.cpp passed.\n";
    return 0;
}
