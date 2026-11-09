/**
 * @file types.cpp
 * @brief Core types and configuration for SIMD-Accelerated Branchless JSON Tokenizer.
 * Module: simd_json_tokenizer
 */

#ifndef SIMD_JSON_TOKENIZER_TYPES_H
#define SIMD_JSON_TOKENIZER_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SIMD_JSON_TOKENIZER_ALIGNMENT 64
#define SIMD_JSON_TOKENIZER_CAPACITY 2048

typedef struct simd_json_tokenizer_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
} simd_json_tokenizer_config_t;

typedef struct simd_json_tokenizer_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    simd_json_tokenizer_config_t config;
} simd_json_tokenizer_state_t;

#endif /* SIMD_JSON_TOKENIZER_TYPES_H */
