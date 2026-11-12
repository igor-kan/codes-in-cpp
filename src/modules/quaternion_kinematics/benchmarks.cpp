/**
 * @file benchmarks.cpp
 * @brief Microbenchmark harness and latency profiling for Hamilton Quaternion 3D Rotation and Normalization.
 * Module: quaternion_kinematics
 */

#include <stdint.h>

#define QUATERNION_KINEMATICS_BENCH_CYCLES 100000

typedef struct quaternion_kinematics_profile_results {
    uint64_t start_tsc;
    uint64_t end_tsc;
    double ops_per_second;
} quaternion_kinematics_profile_results_t;
