#include <iostream>
#include <cmath>
#include <cassert>

double compute_geometric_series_term_127(double x) {
    return std::pow(x, 127) / 127.0;
}

int main() {
    double res = compute_geometric_series_term_127(1.0);
    assert(std::abs(res - (1.0 / 127.0)) < 1e-7);
    return 0;
}
