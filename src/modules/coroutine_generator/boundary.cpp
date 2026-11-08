/**
 * Boundary condition checking and IEEE-754 edge-case handlers for C++20 Coroutine Lazy Sequence Pipeline.
 * Module: coroutine_generator
 */

#ifndef BOUNDARY_COROUTINE_GENERATOR_H
#define BOUNDARY_COROUTINE_GENERATOR_H

#include <math.h>
#include <stdbool.h>

static inline bool coroutine_generator_is_finite_input(double x) {
    return isfinite(x);
}

static inline double coroutine_generator_clamp(double val, double min_val, double max_val) {
    const double t = val < min_val ? min_val : val;
    return t > max_val ? max_val : t;
}

#endif /* BOUNDARY_COROUTINE_GENERATOR_H */
