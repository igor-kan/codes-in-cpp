/**
 * @file benchmarks.cpp
 * @brief Microbenchmark harness and latency profiling for Cacheline-Aligned Circular Deque with Modulo Wrap.
 * Module: deque_ring_buffer
 */

#include <stdint.h>

#define DEQUE_RING_BUFFER_BENCH_ITERATIONS 100000

typedef struct deque_ring_buffer_bench_metrics {
    uint64_t tsc_cycles;
    double ops_per_sec;
} deque_ring_buffer_bench_metrics_t;
