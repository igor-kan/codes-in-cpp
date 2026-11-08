/**
 * Microbenchmark harness and cycle latency profiling for Lock-Free Memory Reclamation via Hazard Pointers.
 * Module: atomic_hazard_pointer
 */

#ifndef BENCH_ATOMIC_HAZARD_POINTER_H
#define BENCH_ATOMIC_HAZARD_POINTER_H

#include <stdint.h>

#define BENCH_WARMUP_ITERATIONS 1000
#define BENCH_SAMPLE_ITERATIONS 100000

typedef struct atomic_hazard_pointer_bench_metrics {
    uint64_t total_cycles;
    uint64_t elapsed_nanoseconds;
    double throughput_elements_per_sec;
} atomic_hazard_pointer_bench_metrics_t;

#endif /* BENCH_ATOMIC_HAZARD_POINTER_H */
