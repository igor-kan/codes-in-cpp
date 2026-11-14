/**
 * @file interface.cpp
 * @brief Abstract function prototypes and contracts for Brent-Dekker Hybrid Root Finder Combining Bisection.
 * Module: brent_dekker_root_solver | Algorithm Family: root_finding
 */

#ifndef BRENT_DEKKER_ROOT_SOLVER_INTERFACE_H
#define BRENT_DEKKER_ROOT_SOLVER_INTERFACE_H

#include "types.cpp"

typedef int (*brent_dekker_root_solver_kernel_fn)(const double* in_vec, double* out_vec, size_t n);

typedef struct brent_dekker_root_solver_vtable {
    int (*init)(brent_dekker_root_solver_state_t* state, const brent_dekker_root_solver_config_t* cfg);
    int (*execute)(brent_dekker_root_solver_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(brent_dekker_root_solver_state_t* state);
    int (*destroy)(brent_dekker_root_solver_state_t* state);
} brent_dekker_root_solver_vtable_t;

#endif /* BRENT_DEKKER_ROOT_SOLVER_INTERFACE_H */
