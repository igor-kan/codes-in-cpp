/**
 * @file boundary.cpp
 * @brief Boundary validation and exceptional input guarding for Cache-Aligned Lock-Free Ring Buffer with Acquire-Release.
 * Module: lockfree_ring_buffer_cpp
 */

#include "types.cpp"
#include <math.h>
#include <stdbool.h>

static inline bool lockfree_ring_buffer_cpp_is_valid_float(double x) {
    return isfinite(x);
}

static inline double lockfree_ring_buffer_cpp_clamp_input(double x, double min_val, double max_val) {
    if (!isfinite(x)) return 0.0;
    if (x < min_val) return min_val;
    if (x > max_val) return max_val;
    return x;
}
