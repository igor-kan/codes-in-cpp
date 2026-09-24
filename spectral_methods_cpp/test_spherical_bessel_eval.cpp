#include "spherical_bessel_eval.hpp"
#include <cassert>
#include <iostream>

int main() {
    assert(j0_bessel(0.0) == 1.0);
    std::cout << "test_spherical_bessel_eval.cpp passed.\n";
    return 0;
}
