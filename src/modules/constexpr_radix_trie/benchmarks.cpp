/**
 * @file benchmarks.cpp
 * @brief Microbenchmark harness and cycle timing for Compile-Time Prefix Radix Trie Router.
 * Module: constexpr_radix_trie
 */

#include <stdint.h>

#define CONSTEXPR_RADIX_TRIE_BENCH_ITERATIONS 100000

typedef struct constexpr_radix_trie_bench_result {
    uint64_t total_cycles;
    double throughput_ops_sec;
} constexpr_radix_trie_bench_result_t;
