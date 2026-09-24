#include "phase_estimation_unitary.hpp"
#include <cassert>
#include <iostream>

int main() {
    double phase = estimate_eigenphase(M_PI);
    assert(std::abs(phase - 0.5) < 1e-7);
    std::cout << "test_phase_estimation_unitary passed.\n";
    return 0;
}
