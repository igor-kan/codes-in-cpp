/**
 * @file benchmarks.cpp
 * @brief Microbenchmark harness and cycle timing for Bounded Multi-Producer Multi-Consumer Queue.
 * Module: lockfree_mpmc_queue
 */

#include <stdint.h>

#define LOCKFREE_MPMC_QUEUE_BENCH_SAMPLES 100000

typedef struct lockfree_mpmc_queue_bench_stats {
    uint64_t cycles;
    double throughput_ops_sec;
} lockfree_mpmc_queue_bench_stats_t;
