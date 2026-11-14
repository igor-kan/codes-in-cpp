/**
 * @file interface.cpp
 * @brief Abstract function prototypes and contracts for Knuth-Morris-Pratt Substring Matcher using LPS Table.
 * Module: kmp_search_vector | Algorithm Family: string_search
 */

#ifndef KMP_SEARCH_VECTOR_INTERFACE_H
#define KMP_SEARCH_VECTOR_INTERFACE_H

#include "types.cpp"

typedef int (*kmp_search_vector_kernel_fn)(const double* in_vec, double* out_vec, size_t n);

typedef struct kmp_search_vector_vtable {
    int (*init)(kmp_search_vector_state_t* state, const kmp_search_vector_config_t* cfg);
    int (*execute)(kmp_search_vector_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(kmp_search_vector_state_t* state);
    int (*destroy)(kmp_search_vector_state_t* state);
} kmp_search_vector_vtable_t;

#endif /* KMP_SEARCH_VECTOR_INTERFACE_H */
