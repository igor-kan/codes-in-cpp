/**
 * @file benchmarks.cpp
 * @brief Microbenchmark harness and cycle timing for Padded 2D Strided Matrix View with Vectorization.
 * Module: simd_matrix_view
 */

#include <stdint.h>

#define SIMD_MATRIX_VIEW_BENCH_SAMPLES 100000

typedef struct simd_matrix_view_bench_stats {
    uint64_t cycles;
    double throughput_ops_sec;
} simd_matrix_view_bench_stats_t;
