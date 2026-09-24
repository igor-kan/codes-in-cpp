#include "bloch_sphere_rotations.hpp"
#include <cassert>
#include <iostream>

int main() {
    std::vector<std::complex<double>> psi = { 1.0, 0.0 };
    auto rotated = rx_rotation(M_PI, psi);
    assert(std::abs(rotated[0]) < 1e-6);
    assert(std::abs(std::abs(rotated[1]) - 1.0) < 1e-6);
    std::cout << "test_bloch_sphere_rotations passed.\n";
    return 0;
}
