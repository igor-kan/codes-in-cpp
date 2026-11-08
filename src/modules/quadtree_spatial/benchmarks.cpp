/**
 * Microbenchmark harness and cycle latency profiling for 2D Spatial Indexing Quadtree with Range Search.
 * Module: quadtree_spatial
 */

#ifndef BENCH_QUADTREE_SPATIAL_H
#define BENCH_QUADTREE_SPATIAL_H

#include <stdint.h>

#define BENCH_WARMUP_ITERATIONS 1000
#define BENCH_SAMPLE_ITERATIONS 100000

typedef struct quadtree_spatial_bench_metrics {
    uint64_t total_cycles;
    uint64_t elapsed_nanoseconds;
    double throughput_elements_per_sec;
} quadtree_spatial_bench_metrics_t;

#endif /* BENCH_QUADTREE_SPATIAL_H */
