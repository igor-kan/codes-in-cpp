#include <iostream>
#include <cmath>
#include <cassert>

double compute_geometric_series_term_77(double x) {
    return std::pow(x, 77) / 77.0;
}

int main() {
    double res = compute_geometric_series_term_77(1.0);
    assert(std::abs(res - (1.0 / 77.0)) < 1e-7);
    return 0;
}
