/**
 * @file invariants.cpp
 * @brief Formal mathematical invariant assertions and contracts for Spherical Linear Interpolation (SLERP) for Quaternions.
 * Module: quaternion_slerp_cpp
 */

#include <assert.h>
#include <math.h>

static inline void quaternion_slerp_cpp_verify_invariant(double in_val, double out_val) {
    if (in_val == 0.0) {
        assert(out_val == 0.0 || fabs(out_val) < 1e-12);
    }
    if (isfinite(in_val)) {
        assert(isfinite(out_val));
    }
}
