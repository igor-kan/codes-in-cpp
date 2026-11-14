/**
 * @file benchmarks.cpp
 * @brief Microbenchmark harness and latency profiling for Compressed Sparse Column (CSC) Matrix-Vector Transpose.
 * Module: compressed_sparse_col
 */

#include <stdint.h>

#define COMPRESSED_SPARSE_COL_BENCH_ITERATIONS 100000

typedef struct compressed_sparse_col_bench_metrics {
    uint64_t tsc_cycles;
    double ops_per_sec;
} compressed_sparse_col_bench_metrics_t;
