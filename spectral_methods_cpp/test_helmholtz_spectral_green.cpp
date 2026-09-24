#include "helmholtz_spectral_green.hpp"
#include <cassert>
#include <iostream>

int main() {
    assert(std::abs(green_free_1d(1.0, 0.0)) < 1e-7);
    std::cout << "test_helmholtz_spectral_green.cpp passed.\n";
    return 0;
}
