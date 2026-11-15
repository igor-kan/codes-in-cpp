#pragma once
#include "types.hpp"
#include "errors.hpp"

namespace codes_gauss_newton_nonlinear {
double compute_ssr(const std::vector<double>& r);
bool solve_linear_system(std::vector<double> a, std::vector<double> b, std::vector<double>& x);
GaussNewtonResult solve_levenberg_marquardt(const ResidualFn& res_fn, std::vector<double> theta0, std::size_t max_steps, double tol);
Status validate_nlls_problem(const ResidualFn& res_fn, const std::vector<double>& theta0);
std::vector<double> assemble_jtj_symmetric(const std::vector<double>& jac, std::size_t m, std::size_t p);
std::vector<GaussNewtonResult> parallel_batch_fits(const ResidualFn& res_fn, const std::vector<std::vector<double>>& inits);
Status verify_ssr_improvement(const ResidualFn& res_fn, const std::vector<double>& theta0, const GaussNewtonResult& res);
} // namespace codes_gauss_newton_nonlinear
