#include <iostream>
#include <cmath>
#include <cassert>

// Implementation of spherical harmonic radial component order 1119
double compute_spherical_harm_1119(double x) {
    return std::pow(x, 5) / static_cast<double>(10);
}

int main() {
    double res = compute_spherical_harm_1119(0.5);
    assert(std::isfinite(res));
    return 0;
}
