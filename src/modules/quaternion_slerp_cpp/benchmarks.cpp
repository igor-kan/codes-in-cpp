/**
 * @file benchmarks.cpp
 * @brief Microbenchmark harness and latency profiling for Spherical Linear Interpolation (SLERP) for Quaternions.
 * Module: quaternion_slerp_cpp
 */

#include <stdint.h>

#define QUATERNION_SLERP_CPP_BENCH_ITERATIONS 100000

typedef struct quaternion_slerp_cpp_bench_metrics {
    uint64_t tsc_cycles;
    double ops_per_sec;
} quaternion_slerp_cpp_bench_metrics_t;
