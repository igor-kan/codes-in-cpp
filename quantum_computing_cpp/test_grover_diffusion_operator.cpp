#include "grover_diffusion_operator.hpp"
#include <cassert>
#include <iostream>

int main() {
    std::vector<double> amps = { 0.5, 0.5, -0.5, 0.5 };
    auto diffused = apply_grover_diffusion(amps);
    assert(diffused.size() == 4);
    std::cout << "test_grover_diffusion_operator passed.\n";
    return 0;
}
