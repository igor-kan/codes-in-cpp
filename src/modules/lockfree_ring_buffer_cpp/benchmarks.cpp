/**
 * @file benchmarks.cpp
 * @brief Microbenchmark harness and cycle timing for Cache-Aligned Lock-Free Ring Buffer with Acquire-Release.
 * Module: lockfree_ring_buffer_cpp
 */

#include <stdint.h>

#define LOCKFREE_RING_BUFFER_CPP_BENCH_SAMPLES 100000

typedef struct lockfree_ring_buffer_cpp_bench_stats {
    uint64_t cycles;
    double throughput_ops_sec;
} lockfree_ring_buffer_cpp_bench_stats_t;
