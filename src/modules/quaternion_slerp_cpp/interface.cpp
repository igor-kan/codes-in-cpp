/**
 * @file interface.cpp
 * @brief Abstract function prototypes and contracts for Spherical Linear Interpolation (SLERP) for Quaternions.
 * Module: quaternion_slerp_cpp | Algorithm Family: quaternion
 */

#ifndef QUATERNION_SLERP_CPP_INTERFACE_H
#define QUATERNION_SLERP_CPP_INTERFACE_H

#include "types.cpp"

typedef int (*quaternion_slerp_cpp_kernel_fn)(const double* in_vec, double* out_vec, size_t n);

typedef struct quaternion_slerp_cpp_vtable {
    int (*init)(quaternion_slerp_cpp_state_t* state, const quaternion_slerp_cpp_config_t* cfg);
    int (*execute)(quaternion_slerp_cpp_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(quaternion_slerp_cpp_state_t* state);
    int (*destroy)(quaternion_slerp_cpp_state_t* state);
} quaternion_slerp_cpp_vtable_t;

#endif /* QUATERNION_SLERP_CPP_INTERFACE_H */
