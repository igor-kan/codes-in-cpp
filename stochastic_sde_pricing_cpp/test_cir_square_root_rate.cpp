#include "cir_square_root_rate.hpp"
#include <cassert>
#include <iostream>

int main() {
    assert(std::abs(cir_drift(2.0, 0.05, 0.04) - 0.02) < 1e-7);
    std::cout << "test_cir_square_root_rate.cpp passed.\n";
    return 0;
}
