/**
 * @file benchmarks.cpp
 * @brief Microbenchmark harness and cycle timing for Cacheline-Aligned B-Tree Node with SIMD Search.
 * Module: simd_b_tree_node
 */

#include <stdint.h>

#define SIMD_B_TREE_NODE_BENCH_SAMPLES 100000

typedef struct simd_b_tree_node_bench_stats {
    uint64_t cycles;
    double throughput_ops_sec;
} simd_b_tree_node_bench_stats_t;
