#include "halton_sequence_quasi_rng.hpp"
#include <cassert>
#include <iostream>

int main() {
    assert(halton_base(1, 2) == 0.5);
    std::cout << "test_halton_sequence_quasi_rng.cpp passed.\n";
    return 0;
}
