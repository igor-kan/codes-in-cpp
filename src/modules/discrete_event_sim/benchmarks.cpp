/**
 * @file benchmarks.cpp
 * @brief Microbenchmark harness and cycle timing for Priority-Queue Discrete Event Simulation Engine.
 * Module: discrete_event_sim
 */

#include <stdint.h>

#define DISCRETE_EVENT_SIM_BENCH_SAMPLES 100000

typedef struct discrete_event_sim_bench_stats {
    uint64_t cycles;
    double throughput_ops_sec;
} discrete_event_sim_bench_stats_t;
