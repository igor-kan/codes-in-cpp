#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_gauss_newton_nonlinear;
    // Exponential curve y = a * exp(b * x) with true a=2.5, b=-0.4
    std::vector<double> xs = {0.0, 1.0, 2.0, 3.0, 4.0, 5.0};
    std::vector<double> ys;
    for (double x : xs) ys.push_back(2.5 * std::exp(-0.4 * x));
    ResidualFn fn = [&](const std::vector<double>& th) {
        std::vector<double> r(xs.size());
        for (std::size_t i = 0; i < xs.size(); ++i) r[i] = th[0] * std::exp(th[1] * xs[i]) - ys[i];
        return r;
    };
    assert(validate_nlls_problem(fn, {1.0, -0.1}) == Status::Ok);
    auto res = solve_levenberg_marquardt(fn, {1.0, -0.1}, 100, 1e-10);
    assert(res.converged);
    assert(std::abs(res.params[0] - 2.5) < 1e-5 && std::abs(res.params[1] - (-0.4)) < 1e-5);
    assert(verify_ssr_improvement(fn, {1.0, -0.1}, res) == Status::Ok);
    return 0;
}
