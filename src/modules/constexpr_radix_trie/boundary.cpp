/**
 * @file boundary.cpp
 * @brief Boundary validation and exceptional input guarding for Compile-Time Prefix Radix Trie Router.
 * Module: constexpr_radix_trie
 */

#include "types.cpp"
#include <math.h>
#include <stdbool.h>

static inline bool constexpr_radix_trie_is_valid_float(double x) {
    return isfinite(x);
}

static inline double constexpr_radix_trie_sanitize_input(double x, double min_bound, double max_bound) {
    if (!isfinite(x)) return 0.0;
    if (x < min_bound) return min_bound;
    if (x > max_bound) return max_bound;
    return x;
}
