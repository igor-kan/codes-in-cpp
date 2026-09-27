#include <iostream>
#include <cmath>
#include <cassert>

double compute_geometric_series_term_132(double x) {
    return std::pow(x, 132) / 132.0;
}

int main() {
    double res = compute_geometric_series_term_132(1.0);
    assert(std::abs(res - (1.0 / 132.0)) < 1e-7);
    return 0;
}
