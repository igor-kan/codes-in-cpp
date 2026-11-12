/**
 * @file interface.cpp
 * @brief Abstract function prototypes and contracts for Boyer-Moore Bad-Character Substring Locator.
 * Module: boyer_moore_search | Algorithm Family: string_search
 */

#ifndef BOYER_MOORE_SEARCH_INTERFACE_H
#define BOYER_MOORE_SEARCH_INTERFACE_H

#include "types.cpp"

typedef int (*boyer_moore_search_kernel_fn)(const double* in_vec, double* out_vec, size_t n);

typedef struct boyer_moore_search_vtable {
    int (*init)(boyer_moore_search_state_t* state, const boyer_moore_search_config_t* cfg);
    int (*execute)(boyer_moore_search_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(boyer_moore_search_state_t* state);
    int (*destroy)(boyer_moore_search_state_t* state);
} boyer_moore_search_vtable_t;

#endif /* BOYER_MOORE_SEARCH_INTERFACE_H */
