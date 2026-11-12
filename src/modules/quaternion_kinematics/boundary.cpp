/**
 * @file boundary.cpp
 * @brief Boundary validation, clamping, and edge-case guards for Hamilton Quaternion 3D Rotation and Normalization.
 * Module: quaternion_kinematics
 */

#include "types.cpp"
#include <math.h>
#include <stdbool.h>

static inline bool quaternion_kinematics_is_finite(double v) {
    return isfinite(v);
}

static inline double quaternion_kinematics_clamp_range(double v, double lo, double hi) {
    if (!isfinite(v)) return 0.0;
    if (v < lo) return lo;
    if (v > hi) return hi;
    return v;
}
