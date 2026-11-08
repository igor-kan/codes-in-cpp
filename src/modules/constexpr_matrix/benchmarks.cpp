/**
 * Microbenchmark harness and cycle latency profiling for Compile-Time Fixed-Size Dense Matrix with LU Solver.
 * Module: constexpr_matrix
 */

#ifndef BENCH_CONSTEXPR_MATRIX_H
#define BENCH_CONSTEXPR_MATRIX_H

#include <stdint.h>

#define BENCH_WARMUP_ITERATIONS 1000
#define BENCH_SAMPLE_ITERATIONS 100000

typedef struct constexpr_matrix_bench_metrics {
    uint64_t total_cycles;
    uint64_t elapsed_nanoseconds;
    double throughput_elements_per_sec;
} constexpr_matrix_bench_metrics_t;

#endif /* BENCH_CONSTEXPR_MATRIX_H */
