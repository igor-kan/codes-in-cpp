#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_gauss_newton_nonlinear;
    // Linear least squares converges in <= 3 steps to exact solution
    std::vector<double> xs = {1.0, 2.0, 3.0, 4.0};
    std::vector<double> ys = {5.0, 8.0, 11.0, 14.0}; // 3x + 2
    ResidualFn fn = [&](const std::vector<double>& th) {
        std::vector<double> r(xs.size());
        for (std::size_t i = 0; i < xs.size(); ++i) r[i] = (th[0] * xs[i] + th[1]) - ys[i];
        return r;
    };
    auto res = solve_levenberg_marquardt(fn, {0.0, 0.0}, 20, 1e-10);
    assert(res.final_ssr < 1e-12);
    assert(std::abs(res.params[0] - 3.0) < 1e-6 && std::abs(res.params[1] - 2.0) < 1e-6);
    return 0;
}
