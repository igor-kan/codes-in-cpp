/**
 * @file interface.cpp
 * @brief Abstract function prototypes and contracts for Continuous Bisection Root-Finding Bracketing Engine.
 * Module: bisection_root_solver | Algorithm Family: root_finding
 */

#ifndef BISECTION_ROOT_SOLVER_INTERFACE_H
#define BISECTION_ROOT_SOLVER_INTERFACE_H

#include "types.cpp"

typedef int (*bisection_root_solver_kernel_fn)(const double* in_vec, double* out_vec, size_t n);

typedef struct bisection_root_solver_vtable {
    int (*init)(bisection_root_solver_state_t* state, const bisection_root_solver_config_t* cfg);
    int (*execute)(bisection_root_solver_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(bisection_root_solver_state_t* state);
    int (*destroy)(bisection_root_solver_state_t* state);
} bisection_root_solver_vtable_t;

#endif /* BISECTION_ROOT_SOLVER_INTERFACE_H */
