#include "milstein_scheme_sde.hpp"
#include <cassert>
#include <iostream>

int main() {
    assert(std::abs(milstein_correction(0.2, 0.01, 0.1) - 0.5 * 0.04 * (0.01 - 0.01)) < 1e-7);
    std::cout << "test_milstein_scheme_sde.cpp passed.\n";
    return 0;
}
