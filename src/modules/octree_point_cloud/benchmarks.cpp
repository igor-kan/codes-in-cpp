/**
 * @file benchmarks.cpp
 * @brief Microbenchmark harness and cycle timing for Hierarchical 3D Point Cloud Octree with Radius Search.
 * Module: octree_point_cloud
 */

#include <stdint.h>

#define OCTREE_POINT_CLOUD_BENCH_SAMPLES 100000

typedef struct octree_point_cloud_bench_stats {
    uint64_t cycles;
    double throughput_ops_sec;
} octree_point_cloud_bench_stats_t;
