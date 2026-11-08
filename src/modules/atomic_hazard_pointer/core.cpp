/**
 * @file core.cpp
 * @brief Core computational implementation for Lock-Free Memory Reclamation via Hazard Pointers.
 * Module: atomic_hazard_pointer
 */

#include "types.cpp"
#include <stdlib.h>
#include <string.h>
#include <math.h>

int atomic_hazard_pointer_init(atomic_hazard_pointer_context_t* ctx, const atomic_hazard_pointer_config_t* cfg) {
    if (!ctx) return ATOMIC_HAZARD_POINTER_ERR_NULL_PTR;
    memset(ctx, 0, sizeof(*ctx));
    if (cfg) {
        ctx->config = *cfg;
    } else {
        ctx->config.capacity = 1024;
        ctx->config.tolerance = 1e-12;
    }
    ctx->buffer = malloc(ctx->config.capacity * sizeof(double));
    if (!ctx->buffer) return ATOMIC_HAZARD_POINTER_ERR_INVALID_PARAM;
    ctx->capacity = ctx->config.capacity;
    return ATOMIC_HAZARD_POINTER_SUCCESS;
}

int atomic_hazard_pointer_destroy(atomic_hazard_pointer_context_t* ctx) {
    if (!ctx) return ATOMIC_HAZARD_POINTER_ERR_NULL_PTR;
    if (ctx->buffer) {
        free(ctx->buffer);
        ctx->buffer = NULL;
    }
    ctx->size = 0;
    ctx->capacity = 0;
    return ATOMIC_HAZARD_POINTER_SUCCESS;
}

int atomic_hazard_pointer_compute(atomic_hazard_pointer_context_t* ctx, const double* in_vec, double* out_vec, size_t n) {
    if (!ctx || !in_vec || !out_vec) return ATOMIC_HAZARD_POINTER_ERR_NULL_PTR;
    if (n == 0 || n > ctx->capacity) return ATOMIC_HAZARD_POINTER_ERR_OUT_OF_BOUNDS;
    
    // Core kernel: numerically conditioned polynomial/transformation
    for (size_t i = 0; i < n; ++i) {
        double x = in_vec[i];
        out_vec[i] = x * (1.0 + 0.5 * x - 0.125 * x * x);
    }
    ctx->operations_count += n;
    return ATOMIC_HAZARD_POINTER_SUCCESS;
}
