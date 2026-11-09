/**
 * @file interface.cpp
 * @brief Abstract contracts and prototypes for SIMD-Accelerated Branchless JSON Tokenizer.
 * Module: simd_json_tokenizer
 */

#ifndef SIMD_JSON_TOKENIZER_INTERFACE_H
#define SIMD_JSON_TOKENIZER_INTERFACE_H

#include "types.cpp"

typedef int (*simd_json_tokenizer_kernel_fn)(const double* in_data, double* out_data, size_t n);

typedef struct simd_json_tokenizer_vtable {
    int (*init)(simd_json_tokenizer_state_t* state, const simd_json_tokenizer_config_t* cfg);
    int (*execute)(simd_json_tokenizer_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*destroy)(simd_json_tokenizer_state_t* state);
} simd_json_tokenizer_vtable_t;

#endif /* SIMD_JSON_TOKENIZER_INTERFACE_H */
