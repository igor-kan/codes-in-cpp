#include "interface.hpp"

namespace codes_gauss_newton_nonlinear {
Status verify_ssr_improvement(const ResidualFn& res_fn, const std::vector<double>& theta0, const GaussNewtonResult& res) {
    if (res.params.size() != theta0.size()) return Status::InvariantViolation;
    double init_ssr = compute_ssr(res_fn(theta0));
    if (res.final_ssr > init_ssr + 1e-12) return Status::InvariantViolation;
    return Status::Ok;
}
} // namespace codes_gauss_newton_nonlinear
