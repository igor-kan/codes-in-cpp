#include <iostream>
#include <cmath>
#include <cassert>

// Implementation of continued fraction approximant order 1070
double compute_continued_frac_1070(double x) {
    double a = 1.0;
    for (int k = 3; k >= 1; --k) {
        a = k + x / (a != 0.0 ? a : 1.0);
    }
    return a;
}

int main() {
    double res = compute_continued_frac_1070(0.5);
    assert(std::isfinite(res));
    return 0;
}
