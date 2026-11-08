/**
 * Boundary condition checking and IEEE-754 edge-case handlers for Lock-Free Memory Reclamation via Hazard Pointers.
 * Module: atomic_hazard_pointer
 */

#ifndef BOUNDARY_ATOMIC_HAZARD_POINTER_H
#define BOUNDARY_ATOMIC_HAZARD_POINTER_H

#include <math.h>
#include <stdbool.h>

static inline bool atomic_hazard_pointer_is_finite_input(double x) {
    return isfinite(x);
}

static inline double atomic_hazard_pointer_clamp(double val, double min_val, double max_val) {
    const double t = val < min_val ? min_val : val;
    return t > max_val ? max_val : t;
}

#endif /* BOUNDARY_ATOMIC_HAZARD_POINTER_H */
