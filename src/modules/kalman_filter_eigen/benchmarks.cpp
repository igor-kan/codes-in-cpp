/**
 * @file benchmarks.cpp
 * @brief Microbenchmark harness and cycle timing for Discrete Linear Kalman Filter State Estimator.
 * Module: kalman_filter_eigen
 */

#include <stdint.h>

#define KALMAN_FILTER_EIGEN_BENCH_ITERATIONS 100000

typedef struct kalman_filter_eigen_bench_result {
    uint64_t total_cycles;
    double throughput_ops_sec;
} kalman_filter_eigen_bench_result_t;
