#include "interface.hpp"
#include <algorithm>
#include <thread>

namespace codes_gauss_newton_nonlinear {
std::vector<GaussNewtonResult> parallel_batch_fits(const ResidualFn& res_fn, const std::vector<std::vector<double>>& inits) {
    std::vector<GaussNewtonResult> out(inits.size());
    std::vector<std::thread> workers;
    const std::size_t nt = std::min<std::size_t>(4, inits.size());
    for (std::size_t t = 0; t < nt; ++t) {
        workers.emplace_back([&, t]() {
            for (std::size_t i = t; i < inits.size(); i += nt) {
                out[i] = solve_levenberg_marquardt(res_fn, inits[i], 100, 1e-8);
            }
        });
    }
    for (auto& w : workers) w.join();
    return out;
}
} // namespace codes_gauss_newton_nonlinear
