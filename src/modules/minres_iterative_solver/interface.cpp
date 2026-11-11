/**
 * @file interface.cpp
 * @brief Abstract contracts and operational prototypes for Minimal Residual (MINRES) Symmetric Indefinite Solver.
 * Module: minres_iterative_solver
 */

#ifndef MINRES_ITERATIVE_SOLVER_INTERFACE_H
#define MINRES_ITERATIVE_SOLVER_INTERFACE_H

#include "types.cpp"

typedef int (*minres_iterative_solver_kernel_fn)(const double* in_data, double* out_data, size_t n);

typedef struct minres_iterative_solver_vtable {
    int (*init)(minres_iterative_solver_state_t* state, const minres_iterative_solver_config_t* cfg);
    int (*execute)(minres_iterative_solver_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(minres_iterative_solver_state_t* state);
    int (*destroy)(minres_iterative_solver_state_t* state);
} minres_iterative_solver_vtable_t;

#endif /* MINRES_ITERATIVE_SOLVER_INTERFACE_H */
