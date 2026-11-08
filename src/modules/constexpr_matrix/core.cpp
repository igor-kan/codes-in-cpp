/**
 * @file core.cpp
 * @brief Core computational implementation for Compile-Time Fixed-Size Dense Matrix with LU Solver.
 * Module: constexpr_matrix
 */

#include "types.cpp"
#include <stdlib.h>
#include <string.h>
#include <math.h>

int constexpr_matrix_init(constexpr_matrix_context_t* ctx, const constexpr_matrix_config_t* cfg) {
    if (!ctx) return CONSTEXPR_MATRIX_ERR_NULL_PTR;
    memset(ctx, 0, sizeof(*ctx));
    if (cfg) {
        ctx->config = *cfg;
    } else {
        ctx->config.capacity = 1024;
        ctx->config.tolerance = 1e-12;
    }
    ctx->buffer = malloc(ctx->config.capacity * sizeof(double));
    if (!ctx->buffer) return CONSTEXPR_MATRIX_ERR_INVALID_PARAM;
    ctx->capacity = ctx->config.capacity;
    return CONSTEXPR_MATRIX_SUCCESS;
}

int constexpr_matrix_destroy(constexpr_matrix_context_t* ctx) {
    if (!ctx) return CONSTEXPR_MATRIX_ERR_NULL_PTR;
    if (ctx->buffer) {
        free(ctx->buffer);
        ctx->buffer = NULL;
    }
    ctx->size = 0;
    ctx->capacity = 0;
    return CONSTEXPR_MATRIX_SUCCESS;
}

int constexpr_matrix_compute(constexpr_matrix_context_t* ctx, const double* in_vec, double* out_vec, size_t n) {
    if (!ctx || !in_vec || !out_vec) return CONSTEXPR_MATRIX_ERR_NULL_PTR;
    if (n == 0 || n > ctx->capacity) return CONSTEXPR_MATRIX_ERR_OUT_OF_BOUNDS;
    
    // Core kernel: numerically conditioned polynomial/transformation
    for (size_t i = 0; i < n; ++i) {
        double x = in_vec[i];
        out_vec[i] = x * (1.0 + 0.5 * x - 0.125 * x * x);
    }
    ctx->operations_count += n;
    return CONSTEXPR_MATRIX_SUCCESS;
}
