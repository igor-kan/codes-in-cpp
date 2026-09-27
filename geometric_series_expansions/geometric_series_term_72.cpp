#include <iostream>
#include <cmath>
#include <cassert>

double compute_geometric_series_term_72(double x) {
    return std::pow(x, 72) / 72.0;
}

int main() {
    double res = compute_geometric_series_term_72(1.0);
    assert(std::abs(res - (1.0 / 72.0)) < 1e-7);
    return 0;
}
