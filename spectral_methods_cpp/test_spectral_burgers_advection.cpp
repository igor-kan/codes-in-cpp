#include "spectral_burgers_advection.hpp"
#include <cassert>
#include <iostream>

int main() {
    assert(burgers_flux(2.0) == 2.0);
    std::cout << "test_spectral_burgers_advection.cpp passed.\n";
    return 0;
}
