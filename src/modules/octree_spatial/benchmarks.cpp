/**
 * @file benchmarks.cpp
 * @brief Microbenchmark harness and cycle timing for 3D Spatial Partitioning Octree with Frustum Culling.
 * Module: octree_spatial
 */

#include <stdint.h>

#define OCTREE_SPATIAL_BENCH_SAMPLES 100000

typedef struct octree_spatial_bench_stats {
    uint64_t cycles;
    double throughput_ops_sec;
} octree_spatial_bench_stats_t;
