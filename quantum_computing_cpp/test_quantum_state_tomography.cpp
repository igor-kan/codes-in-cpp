#include "quantum_state_tomography.hpp"
#include <cassert>
#include <iostream>

int main() {
    auto b = bloch_coordinates_from_expectations(0.0, 0.0, 1.0);
    assert(b[2] == 1.0);
    std::cout << "test_quantum_state_tomography passed.\n";
    return 0;
}
