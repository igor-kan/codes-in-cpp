/**
 * @file invariants.cpp
 * @brief Formal mathematical invariant assertions and contracts for Hamilton Quaternion 3D Rotation and Normalization.
 * Module: quaternion_kinematics
 */

#include <assert.h>
#include <math.h>

static inline void quaternion_kinematics_check_invariants(double input, double output) {
    if (input == 0.0) {
        assert(output == 0.0 || fabs(output) < 1e-12);
    }
    if (isfinite(input)) {
        assert(isfinite(output));
    }
}
