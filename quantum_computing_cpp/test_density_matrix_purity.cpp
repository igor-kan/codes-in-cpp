#include "density_matrix_purity.hpp"
#include <cassert>
#include <iostream>

int main() {
    std::vector<std::vector<std::complex<double>>> rho = {
        { 0.5, 0.0 },
        { 0.0, 0.5 }
    };
    double p = calculate_matrix_purity(rho);
    assert(std::abs(p - 0.5) < 1e-7);
    std::cout << "test_density_matrix_purity passed.\n";
    return 0;
}
