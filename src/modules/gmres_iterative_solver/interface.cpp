/**
 * @file interface.cpp
 * @brief Abstract contracts and prototypes for Generalized Minimal Residual (GMRES) Sparse Solver.
 * Module: gmres_iterative_solver
 */

#ifndef GMRES_ITERATIVE_SOLVER_INTERFACE_H
#define GMRES_ITERATIVE_SOLVER_INTERFACE_H

#include "types.cpp"

typedef int (*gmres_iterative_solver_kernel_fn)(const double* in_data, double* out_data, size_t n);

typedef struct gmres_iterative_solver_vtable {
    int (*init)(gmres_iterative_solver_state_t* state, const gmres_iterative_solver_config_t* cfg);
    int (*execute)(gmres_iterative_solver_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*destroy)(gmres_iterative_solver_state_t* state);
} gmres_iterative_solver_vtable_t;

#endif /* GMRES_ITERATIVE_SOLVER_INTERFACE_H */
