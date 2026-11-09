/**
 * @file benchmarks.cpp
 * @brief Microbenchmark harness and cycle timing for Compact Patricia Trie with Bitwise Prefix Match.
 * Module: radix_tree_patricia
 */

#include <stdint.h>

#define RADIX_TREE_PATRICIA_BENCH_SAMPLES 100000

typedef struct radix_tree_patricia_bench_stats {
    uint64_t cycles;
    double throughput_ops_sec;
} radix_tree_patricia_bench_stats_t;
