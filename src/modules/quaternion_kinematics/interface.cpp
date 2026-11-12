/**
 * @file interface.cpp
 * @brief Abstract function prototypes and contracts for Hamilton Quaternion 3D Rotation and Normalization.
 * Module: quaternion_kinematics | Algorithm Family: quaternion
 */

#ifndef QUATERNION_KINEMATICS_INTERFACE_H
#define QUATERNION_KINEMATICS_INTERFACE_H

#include "types.cpp"

typedef int (*quaternion_kinematics_kernel_fn)(const double* in_vec, double* out_vec, size_t n);

typedef struct quaternion_kinematics_vtable {
    int (*init)(quaternion_kinematics_state_t* state, const quaternion_kinematics_config_t* cfg);
    int (*execute)(quaternion_kinematics_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(quaternion_kinematics_state_t* state);
    int (*destroy)(quaternion_kinematics_state_t* state);
} quaternion_kinematics_vtable_t;

#endif /* QUATERNION_KINEMATICS_INTERFACE_H */
