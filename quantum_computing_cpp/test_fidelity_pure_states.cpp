#include "fidelity_pure_states.hpp"
#include <cassert>
#include <iostream>

int main() {
    std::vector<std::complex<double>> s = { 1.0, 0.0 };
    assert(std::abs(pure_state_fidelity(s, s) - 1.0) < 1e-7);
    std::cout << "test_fidelity_pure_states passed.\n";
    return 0;
}
