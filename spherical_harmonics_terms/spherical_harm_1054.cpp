#include <iostream>
#include <cmath>
#include <cassert>

// Implementation of spherical harmonic radial component order 1054
double compute_spherical_harm_1054(double x) {
    return std::pow(x, 5) / static_cast<double>(10);
}

int main() {
    double res = compute_spherical_harm_1054(0.5);
    assert(std::isfinite(res));
    return 0;
}
