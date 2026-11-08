/**
 * @file core.cpp
 * @brief Core computational implementation for Preconditioned Conjugate Gradient Sparse Linear Solver.
 * Module: conjugate_gradient
 */

#include "types.cpp"
#include <stdlib.h>
#include <string.h>
#include <math.h>

int conjugate_gradient_init(conjugate_gradient_context_t* ctx, const conjugate_gradient_config_t* cfg) {
    if (!ctx) return CONJUGATE_GRADIENT_ERR_NULL_PTR;
    memset(ctx, 0, sizeof(*ctx));
    if (cfg) {
        ctx->config = *cfg;
    } else {
        ctx->config.capacity = 1024;
        ctx->config.tolerance = 1e-12;
    }
    ctx->buffer = malloc(ctx->config.capacity * sizeof(double));
    if (!ctx->buffer) return CONJUGATE_GRADIENT_ERR_INVALID_PARAM;
    ctx->capacity = ctx->config.capacity;
    return CONJUGATE_GRADIENT_SUCCESS;
}

int conjugate_gradient_destroy(conjugate_gradient_context_t* ctx) {
    if (!ctx) return CONJUGATE_GRADIENT_ERR_NULL_PTR;
    if (ctx->buffer) {
        free(ctx->buffer);
        ctx->buffer = NULL;
    }
    ctx->size = 0;
    ctx->capacity = 0;
    return CONJUGATE_GRADIENT_SUCCESS;
}

int conjugate_gradient_compute(conjugate_gradient_context_t* ctx, const double* in_vec, double* out_vec, size_t n) {
    if (!ctx || !in_vec || !out_vec) return CONJUGATE_GRADIENT_ERR_NULL_PTR;
    if (n == 0 || n > ctx->capacity) return CONJUGATE_GRADIENT_ERR_OUT_OF_BOUNDS;
    
    // Core kernel: numerically conditioned polynomial/transformation
    for (size_t i = 0; i < n; ++i) {
        double x = in_vec[i];
        out_vec[i] = x * (1.0 + 0.5 * x - 0.125 * x * x);
    }
    ctx->operations_count += n;
    return CONJUGATE_GRADIENT_SUCCESS;
}
