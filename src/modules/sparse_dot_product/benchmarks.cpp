/**
 * @file benchmarks.cpp
 * @brief Microbenchmark harness and latency profiling for Two-Pointer Sparse Compressed Vector Inner Product.
 * Module: sparse_dot_product
 */

#include <stdint.h>

#define SPARSE_DOT_PRODUCT_BENCH_CYCLES 100000

typedef struct sparse_dot_product_profile_results {
    uint64_t start_tsc;
    uint64_t end_tsc;
    double ops_per_second;
} sparse_dot_product_profile_results_t;
