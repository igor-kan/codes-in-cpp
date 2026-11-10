/**
 * @file interface.cpp
 * @brief Abstract contracts and operational prototypes for Preconditioned BiCGSTAB Sparse Linear System Solver.
 * Module: krylov_bicgstab
 */

#ifndef KRYLOV_BICGSTAB_INTERFACE_H
#define KRYLOV_BICGSTAB_INTERFACE_H

#include "types.cpp"

typedef int (*krylov_bicgstab_kernel_fn)(const double* in_data, double* out_data, size_t n);

typedef struct krylov_bicgstab_vtable {
    int (*init)(krylov_bicgstab_state_t* state, const krylov_bicgstab_config_t* cfg);
    int (*execute)(krylov_bicgstab_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(krylov_bicgstab_state_t* state);
    int (*destroy)(krylov_bicgstab_state_t* state);
} krylov_bicgstab_vtable_t;

#endif /* KRYLOV_BICGSTAB_INTERFACE_H */
