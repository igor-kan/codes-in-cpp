/**
 * @file benchmarks.cpp
 * @brief Microbenchmark harness and cycle timing for Cacheline-Aligned CSR Sparse Matrix View with Vectorization.
 * Module: simd_csr_matrix_view
 */

#include <stdint.h>

#define SIMD_CSR_MATRIX_VIEW_BENCH_SAMPLES 100000

typedef struct simd_csr_matrix_view_bench_stats {
    uint64_t cycles;
    double throughput_ops_sec;
} simd_csr_matrix_view_bench_stats_t;
