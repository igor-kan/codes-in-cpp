/**
 * Microbenchmark harness and cycle latency profiling for Strided Multi-Dimensional Tensor View with SIMD Alignment.
 * Module: simd_tensor_view
 */

#ifndef BENCH_SIMD_TENSOR_VIEW_H
#define BENCH_SIMD_TENSOR_VIEW_H

#include <stdint.h>

#define BENCH_WARMUP_ITERATIONS 1000
#define BENCH_SAMPLE_ITERATIONS 100000

typedef struct simd_tensor_view_bench_metrics {
    uint64_t total_cycles;
    uint64_t elapsed_nanoseconds;
    double throughput_elements_per_sec;
} simd_tensor_view_bench_metrics_t;

#endif /* BENCH_SIMD_TENSOR_VIEW_H */
