/**
 * Microbenchmark harness and cycle latency profiling for C++20 Concept Constraints for Algebraic Vector Spaces.
 * Module: concepts_linear_algebra
 */

#ifndef BENCH_CONCEPTS_LINEAR_ALGEBRA_H
#define BENCH_CONCEPTS_LINEAR_ALGEBRA_H

#include <stdint.h>

#define BENCH_WARMUP_ITERATIONS 1000
#define BENCH_SAMPLE_ITERATIONS 100000

typedef struct concepts_linear_algebra_bench_metrics {
    uint64_t total_cycles;
    uint64_t elapsed_nanoseconds;
    double throughput_elements_per_sec;
} concepts_linear_algebra_bench_metrics_t;

#endif /* BENCH_CONCEPTS_LINEAR_ALGEBRA_H */
