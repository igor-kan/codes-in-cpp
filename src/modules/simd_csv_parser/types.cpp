/**
 * @file types.cpp
 * @brief Core types and configuration for SIMD-Accelerated Branchless CSV Row Parser and Scanner.
 * Module: simd_csv_parser
 */

#ifndef SIMD_CSV_PARSER_TYPES_H
#define SIMD_CSV_PARSER_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SIMD_CSV_PARSER_ALIGNMENT 64
#define SIMD_CSV_PARSER_DEFAULT_SZ 8192

typedef struct simd_csv_parser_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
} simd_csv_parser_config_t;

typedef struct simd_csv_parser_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    simd_csv_parser_config_t config;
} simd_csv_parser_state_t;

#endif /* SIMD_CSV_PARSER_TYPES_H */
