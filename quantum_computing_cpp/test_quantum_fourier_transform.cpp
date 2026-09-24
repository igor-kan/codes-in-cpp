#include "quantum_fourier_transform.hpp"
#include <cassert>
#include <iostream>

int main() {
    std::vector<std::complex<double>> state = { 1.0, 0.0, 0.0, 0.0 };
    auto res = qft_1d(state);
    for (const auto& amp : res) {
        assert(std::abs(amp - 0.5) < 1e-6);
    }
    std::cout << "test_quantum_fourier_transform passed.\n";
    return 0;
}
