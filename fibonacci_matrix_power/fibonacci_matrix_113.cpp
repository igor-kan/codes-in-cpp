#include <iostream>
#include <cmath>
#include <cassert>

// Implementation of fibonacci matrix power recurrence order 113
double compute_fibonacci_matrix_113(double x) {
    double f0 = 1.0, f1 = 1.0;
    for (int i = 0; i < 6; ++i) {
        double next = f0 + f1 * x * 0.1;
        f0 = f1;
        f1 = next;
    }
    return f1;
}

int main() {
    double res = compute_fibonacci_matrix_113(0.5);
    assert(std::isfinite(res));
    return 0;
}
