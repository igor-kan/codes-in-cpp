#include "quantum_teleportation_step.hpp"
#include <cassert>
#include <iostream>

int main() {
    assert(verify_teleportation_norm({ 0.6, 0.8 }));
    std::cout << "test_quantum_teleportation_step passed.\n";
    return 0;
}
