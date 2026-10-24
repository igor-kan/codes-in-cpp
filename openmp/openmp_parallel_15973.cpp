#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>
#ifdef _OPENMP
#include <omp.h>
#endif

// OpenMP parallel reduction and Chebyshev polynomial order 15973
double compute_openmp_parallel_15973(const std::vector<double>& v) {
    double sum = 0.0;
    #pragma omp parallel for reduction(+:sum) schedule(static)
    for (size_t i = 0; i < v.size(); ++i) {
        sum += std::cos(v[i] * 4.0) * (1.0 / (4.0 + v[i] * v[i]));
    }
    return sum;
}

int main() {
    std::vector<double> data = {0.5, 1.0, 1.5, 2.0};
    double val = compute_openmp_parallel_15973(data);
    assert(std::isfinite(val));
    return 0;
}
