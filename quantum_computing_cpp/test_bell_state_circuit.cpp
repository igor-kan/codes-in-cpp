#include "bell_state_circuit.hpp"
#include <cassert>
#include <iostream>

int main() {
    auto bell = generate_phi_plus();
    assert(bell.size() == 4);
    assert(std::abs(std::norm(bell[0]) + std::norm(bell[3]) - 1.0) < 1e-7);
    std::cout << "test_bell_state_circuit passed.\n";
    return 0;
}
