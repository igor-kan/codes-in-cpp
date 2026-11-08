/**
 * @file benchmarks.cpp
 * @brief Microbenchmark harness and cycle timing for 2D Spatial Collision Quadtree with Range Pruning.
 * Module: quadtree_collision
 */

#include <stdint.h>

#define QUADTREE_COLLISION_BENCH_ITERATIONS 100000

typedef struct quadtree_collision_bench_result {
    uint64_t total_cycles;
    double throughput_ops_sec;
} quadtree_collision_bench_result_t;
