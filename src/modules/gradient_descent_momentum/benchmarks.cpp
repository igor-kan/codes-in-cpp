/**
 * @file benchmarks.cpp
 * @brief Microbenchmark harness and latency profiling for Gradient Descent Optimizer with Nesterov Momentum.
 * Module: gradient_descent_momentum
 */

#include <stdint.h>

#define GRADIENT_DESCENT_MOMENTUM_BENCH_ITERATIONS 100000

typedef struct gradient_descent_momentum_bench_metrics {
    uint64_t tsc_cycles;
    double ops_per_sec;
} gradient_descent_momentum_bench_metrics_t;
