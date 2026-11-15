#include "interface.hpp"

namespace codes_gauss_newton_nonlinear {
Status validate_nlls_problem(const ResidualFn& res_fn, const std::vector<double>& theta0) {
    if (theta0.empty()) return Status::NullOrEmpty;
    if (res_fn(theta0).size() < theta0.size()) return Status::InvalidInput;
    return Status::Ok;
}
} // namespace codes_gauss_newton_nonlinear
