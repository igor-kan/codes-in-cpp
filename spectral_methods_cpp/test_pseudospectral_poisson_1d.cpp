#include "pseudospectral_poisson_1d.hpp"
#include <cassert>
#include <iostream>

int main() {
    assert(poisson_eigenmode(1, M_PI) == -1.0);
    std::cout << "test_pseudospectral_poisson_1d.cpp passed.\n";
    return 0;
}
