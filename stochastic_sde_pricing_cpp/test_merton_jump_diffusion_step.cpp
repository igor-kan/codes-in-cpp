#include "merton_jump_diffusion_step.hpp"
#include <cassert>
#include <iostream>

int main() {
    assert(std::abs(merton_drift_adjust(0.5, 0.1) - 0.05) < 1e-7);
    std::cout << "test_merton_jump_diffusion_step.cpp passed.\n";
    return 0;
}
