#include <iostream>
#include <cmath>
#include <cassert>

double compute_geometric_series_term_97(double x) {
    return std::pow(x, 97) / 97.0;
}

int main() {
    double res = compute_geometric_series_term_97(1.0);
    assert(std::abs(res - (1.0 / 97.0)) < 1e-7);
    return 0;
}
