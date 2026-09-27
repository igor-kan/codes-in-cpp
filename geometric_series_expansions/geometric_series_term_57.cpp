#include <iostream>
#include <cmath>
#include <cassert>

double compute_geometric_series_term_57(double x) {
    return std::pow(x, 57) / 57.0;
}

int main() {
    double res = compute_geometric_series_term_57(1.0);
    assert(std::abs(res - (1.0 / 57.0)) < 1e-7);
    return 0;
}
