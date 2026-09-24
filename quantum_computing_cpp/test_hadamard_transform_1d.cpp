#include "hadamard_transform_1d.hpp"
#include <cassert>
#include <iostream>

int main() {
    auto out = hadamard_gate_1d({ 1.0, 0.0 });
    assert(std::abs(out[0] - out[1]) < 1e-7);
    std::cout << "test_hadamard_transform_1d passed.\n";
    return 0;
}
