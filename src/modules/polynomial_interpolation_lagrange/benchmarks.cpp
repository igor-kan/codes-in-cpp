/**
 * @file benchmarks.cpp
 * @brief Microbenchmark harness and latency profiling for Barycentric Lagrange Polynomial Interpolator.
 * Module: polynomial_interpolation_lagrange
 */

#include <stdint.h>

#define POLYNOMIAL_INTERPOLATION_LAGRANGE_BENCH_ITERATIONS 100000

typedef struct polynomial_interpolation_lagrange_bench_metrics {
    uint64_t tsc_cycles;
    double ops_per_sec;
} polynomial_interpolation_lagrange_bench_metrics_t;
