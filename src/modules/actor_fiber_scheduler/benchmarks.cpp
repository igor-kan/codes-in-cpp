/**
 * @file benchmarks.cpp
 * @brief Microbenchmark harness and cycle timing for Cooperative Fiber Scheduler with Work-Stealing Queues.
 * Module: actor_fiber_scheduler
 */

#include <stdint.h>

#define ACTOR_FIBER_SCHEDULER_BENCH_SAMPLES 100000

typedef struct actor_fiber_scheduler_bench_stats {
    uint64_t cycles;
    double throughput_ops_sec;
} actor_fiber_scheduler_bench_stats_t;
