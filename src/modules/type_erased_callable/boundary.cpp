/**
 * @file boundary.cpp
 * @brief Boundary validation and exceptional input guarding for Small Buffer Optimized Type-Erased Callable.
 * Module: type_erased_callable
 */

#include "types.cpp"
#include <math.h>
#include <stdbool.h>

static inline bool type_erased_callable_is_valid_float(double x) {
    return isfinite(x);
}

static inline double type_erased_callable_clamp_input(double x, double min_val, double max_val) {
    if (!isfinite(x)) return 0.0;
    if (x < min_val) return min_val;
    if (x > max_val) return max_val;
    return x;
}
