/**
 * @file interface.cpp
 * @brief Abstract contracts and operational prototypes for SIMD-Accelerated Branchless CSV Row Parser and Scanner.
 * Module: simd_csv_parser
 */

#ifndef SIMD_CSV_PARSER_INTERFACE_H
#define SIMD_CSV_PARSER_INTERFACE_H

#include "types.cpp"

typedef int (*simd_csv_parser_kernel_fn)(const double* in_data, double* out_data, size_t n);

typedef struct simd_csv_parser_vtable {
    int (*init)(simd_csv_parser_state_t* state, const simd_csv_parser_config_t* cfg);
    int (*execute)(simd_csv_parser_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(simd_csv_parser_state_t* state);
    int (*destroy)(simd_csv_parser_state_t* state);
} simd_csv_parser_vtable_t;

#endif /* SIMD_CSV_PARSER_INTERFACE_H */
