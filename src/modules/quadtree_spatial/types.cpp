/**
 * @file types.cpp
 * @brief Core type definitions and operational interfaces for 2D Spatial Indexing Quadtree with Range Search.
 * Module: quadtree_spatial
 */

#ifndef QUADTREE_SPATIAL_TYPES_H
#define QUADTREE_SPATIAL_TYPES_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#define QUADTREE_SPATIAL_ALIGNMENT 64
#define QUADTREE_SPATIAL_SUCCESS 0
#define QUADTREE_SPATIAL_ERR_NULL_PTR -1
#define QUADTREE_SPATIAL_ERR_INVALID_PARAM -2
#define QUADTREE_SPATIAL_ERR_OUT_OF_BOUNDS -3

typedef struct quadtree_spatial_config {
    size_t capacity;
    uint32_t flags;
    double tolerance;
} quadtree_spatial_config_t;

typedef struct quadtree_spatial_context {
    void* buffer;
    size_t size;
    size_t capacity;
    uint64_t operations_count;
    quadtree_spatial_config_t config;
} quadtree_spatial_context_t;

int quadtree_spatial_init(quadtree_spatial_context_t* ctx, const quadtree_spatial_config_t* cfg);
int quadtree_spatial_destroy(quadtree_spatial_context_t* ctx);

#ifdef __cplusplus
}
#endif

#endif /* QUADTREE_SPATIAL_TYPES_H */
