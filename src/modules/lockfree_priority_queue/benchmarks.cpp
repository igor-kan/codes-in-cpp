/**
 * @file benchmarks.cpp
 * @brief Microbenchmark harness and cycle timing for Bounded Lock-Free Priority Queue with Atomic SkipList.
 * Module: lockfree_priority_queue
 */

#include <stdint.h>

#define LOCKFREE_PRIORITY_QUEUE_BENCH_SAMPLES 100000

typedef struct lockfree_priority_queue_bench_stats {
    uint64_t cycles;
    double throughput_ops_sec;
} lockfree_priority_queue_bench_stats_t;
