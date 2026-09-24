#include "toffoli_gate_matrix.hpp"
#include <cassert>
#include <iostream>

int main() {
    std::vector<double> s(8, 0.0);
    s[6] = 1.0;
    auto out = apply_toffoli_3qubit(s);
    assert(out[7] == 1.0);
    std::cout << "test_toffoli_gate_matrix passed.\n";
    return 0;
}
