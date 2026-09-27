#include <iostream>
#include <cmath>
#include <cassert>

double compute_geometric_series_term_107(double x) {
    return std::pow(x, 107) / 107.0;
}

int main() {
    double res = compute_geometric_series_term_107(1.0);
    assert(std::abs(res - (1.0 / 107.0)) < 1e-7);
    return 0;
}
