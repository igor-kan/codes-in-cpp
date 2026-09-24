#include "sobol_quasi_random_1d.hpp"
#include <cassert>
#include <iostream>

int main() {
    assert(sobol_van_der_corput(1) == 0.5); assert(sobol_van_der_corput(2) == 0.25);
    std::cout << "test_sobol_quasi_random_1d.cpp passed.\n";
    return 0;
}
