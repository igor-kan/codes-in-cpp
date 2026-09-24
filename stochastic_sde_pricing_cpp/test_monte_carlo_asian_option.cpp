#include "monte_carlo_asian_option.hpp"
#include <cassert>
#include <iostream>

int main() {
    assert(arithmetic_average({10, 20, 30}) == 20.0);
    std::cout << "test_monte_carlo_asian_option.cpp passed.\n";
    return 0;
}
