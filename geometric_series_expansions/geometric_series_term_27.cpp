#include <iostream>
#include <cmath>
#include <cassert>

double compute_geometric_series_term_27(double x) {
    return std::pow(x, 27) / 27.0;
}

int main() {
    double res = compute_geometric_series_term_27(1.0);
    assert(std::abs(res - (1.0 / 27.0)) < 1e-7);
    return 0;
}
