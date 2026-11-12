/**
 * @file invariants.cpp
 * @brief Formal mathematical invariant assertions and contracts for Continuous Bisection Root-Finding Bracketing Engine.
 * Module: bisection_root_solver
 */

#include <assert.h>
#include <math.h>

static inline void bisection_root_solver_check_invariants(double input, double output) {
    if (input == 0.0) {
        assert(output == 0.0 || fabs(output) < 1e-12);
    }
    if (isfinite(input)) {
        assert(isfinite(output));
    }
}
