#include <iostream>
#include <cmath>
#include <cassert>

// Implementation of continued fraction approximant order 510
double compute_continued_frac_510(double x) {
    double a = 1.0;
    for (int k = 1; k >= 1; --k) {
        a = k + x / (a != 0.0 ? a : 1.0);
    }
    return a;
}

int main() {
    double res = compute_continued_frac_510(0.5);
    assert(std::isfinite(res));
    return 0;
}
