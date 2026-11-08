/**
 * @file benchmarks.cpp
 * @brief Microbenchmark harness and cycle timing for Cacheline-Aligned Lock-Free SPSC Queue.
 * Module: lockfree_spsc_queue
 */

#include <stdint.h>

#define LOCKFREE_SPSC_QUEUE_BENCH_ITERATIONS 100000

typedef struct lockfree_spsc_queue_bench_result {
    uint64_t total_cycles;
    double throughput_ops_sec;
} lockfree_spsc_queue_bench_result_t;
