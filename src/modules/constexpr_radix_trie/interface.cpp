/**
 * @file interface.cpp
 * @brief Abstract contracts and operational prototypes for Compile-Time Prefix Radix Trie Router.
 * Module: constexpr_radix_trie
 */

#ifndef CONSTEXPR_RADIX_TRIE_INTERFACE_H
#define CONSTEXPR_RADIX_TRIE_INTERFACE_H

#include "types.cpp"

typedef int (*constexpr_radix_trie_transform_fn)(const double* in_data, double* out_data, size_t n);

typedef struct constexpr_radix_trie_interface {
    int (*init)(constexpr_radix_trie_state_t* state, const constexpr_radix_trie_config_t* cfg);
    int (*execute)(constexpr_radix_trie_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(constexpr_radix_trie_state_t* state);
    int (*destroy)(constexpr_radix_trie_state_t* state);
} constexpr_radix_trie_interface_t;

#endif /* CONSTEXPR_RADIX_TRIE_INTERFACE_H */
