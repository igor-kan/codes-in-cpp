/**
 * @file benchmarks.cpp
 * @brief Microbenchmark harness and cycle timing for 3D Octree Hierarchical Bounding Box Ray Accelerator.
 * Module: octree_ray_caster
 */

#include <stdint.h>

#define OCTREE_RAY_CASTER_BENCH_SAMPLES 100000

typedef struct octree_ray_caster_bench_stats {
    uint64_t cycles;
    double throughput_ops_sec;
} octree_ray_caster_bench_stats_t;
