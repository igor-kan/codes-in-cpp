/**
 * Microbenchmark harness and cycle latency profiling for Preconditioned Conjugate Gradient Sparse Linear Solver.
 * Module: conjugate_gradient
 */

#ifndef BENCH_CONJUGATE_GRADIENT_H
#define BENCH_CONJUGATE_GRADIENT_H

#include <stdint.h>

#define BENCH_WARMUP_ITERATIONS 1000
#define BENCH_SAMPLE_ITERATIONS 100000

typedef struct conjugate_gradient_bench_metrics {
    uint64_t total_cycles;
    uint64_t elapsed_nanoseconds;
    double throughput_elements_per_sec;
} conjugate_gradient_bench_metrics_t;

#endif /* BENCH_CONJUGATE_GRADIENT_H */
