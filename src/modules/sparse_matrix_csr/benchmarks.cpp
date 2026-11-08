/**
 * @file benchmarks.cpp
 * @brief Microbenchmark harness and cycle timing for Compressed Sparse Row Matrix SpMV Acceleration.
 * Module: sparse_matrix_csr
 */

#include <stdint.h>

#define SPARSE_MATRIX_CSR_BENCH_ITERATIONS 100000

typedef struct sparse_matrix_csr_bench_result {
    uint64_t total_cycles;
    double throughput_ops_sec;
} sparse_matrix_csr_bench_result_t;
