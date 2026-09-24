#include "fourier_spectral_differentiation.hpp"
#include <cassert>
#include <iostream>

int main() {
    assert(spectral_diff_k(2.0, 1.0) == -4.0);
    std::cout << "test_fourier_spectral_differentiation.cpp passed.\n";
    return 0;
}
