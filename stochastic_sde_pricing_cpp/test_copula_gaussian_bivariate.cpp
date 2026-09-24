#include "copula_gaussian_bivariate.hpp"
#include <cassert>
#include <iostream>

int main() {
    auto [x1, x2] = correlated_normals(1.0, 0.0, 0.6); assert(std::abs(x2 - 0.6) < 1e-7);
    std::cout << "test_copula_gaussian_bivariate.cpp passed.\n";
    return 0;
}
