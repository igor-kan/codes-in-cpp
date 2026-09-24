#include "pauli_twirl_channel.hpp"
#include <cassert>
#include <iostream>

int main() {
    assert(std::abs(depolarizing_fidelity(0.0) - 1.0) < 1e-7);
    assert(std::abs(depolarizing_fidelity(0.1) - 0.95) < 1e-7);
    std::cout << "test_pauli_twirl_channel passed.\n";
    return 0;
}
