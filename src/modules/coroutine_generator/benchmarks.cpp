/**
 * Microbenchmark harness and cycle latency profiling for C++20 Coroutine Lazy Sequence Pipeline.
 * Module: coroutine_generator
 */

#ifndef BENCH_COROUTINE_GENERATOR_H
#define BENCH_COROUTINE_GENERATOR_H

#include <stdint.h>

#define BENCH_WARMUP_ITERATIONS 1000
#define BENCH_SAMPLE_ITERATIONS 100000

typedef struct coroutine_generator_bench_metrics {
    uint64_t total_cycles;
    uint64_t elapsed_nanoseconds;
    double throughput_elements_per_sec;
} coroutine_generator_bench_metrics_t;

#endif /* BENCH_COROUTINE_GENERATOR_H */
