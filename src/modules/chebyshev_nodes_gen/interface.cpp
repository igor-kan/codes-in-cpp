/**
 * @file interface.cpp
 * @brief Abstract function prototypes and contracts for Chebyshev-Gauss Roots and Extrema Node Generator.
 * Module: chebyshev_nodes_gen | Algorithm Family: collocation
 */

#ifndef CHEBYSHEV_NODES_GEN_INTERFACE_H
#define CHEBYSHEV_NODES_GEN_INTERFACE_H

#include "types.cpp"

typedef int (*chebyshev_nodes_gen_kernel_fn)(const double* in_vec, double* out_vec, size_t n);

typedef struct chebyshev_nodes_gen_vtable {
    int (*init)(chebyshev_nodes_gen_state_t* state, const chebyshev_nodes_gen_config_t* cfg);
    int (*execute)(chebyshev_nodes_gen_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(chebyshev_nodes_gen_state_t* state);
    int (*destroy)(chebyshev_nodes_gen_state_t* state);
} chebyshev_nodes_gen_vtable_t;

#endif /* CHEBYSHEV_NODES_GEN_INTERFACE_H */
