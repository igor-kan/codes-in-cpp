#include "cnot_gate_matrix.hpp"
#include <cassert>
#include <iostream>

int main() {
    std::vector<double> state = { 0, 0, 1, 0 }; // |10> -> |11>
    auto out = apply_cnot_2qubit(state);
    assert(out[3] == 1.0);
    std::cout << "test_cnot_gate_matrix passed.\n";
    return 0;
}
