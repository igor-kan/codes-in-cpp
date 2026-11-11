/**
 * @file invariants.cpp
 * @brief Mathematical invariants and contract assertions for Minimal Residual (MINRES) Symmetric Indefinite Solver.
 * Module: minres_iterative_solver
 */

#include <assert.h>
#include <math.h>

static inline void minres_iterative_solver_verify_contract_day47(double in_val, double out_val) {
    if (in_val == 0.0) {
        assert(out_val == 0.0);
    }
    if (isfinite(in_val)) {
        assert(isfinite(out_val));
    }
}
