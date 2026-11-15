#include "interface.hpp"
#include <chrono>
#include <cmath>
#include <cstddef>
#include <iostream>

int main() {
    std::size_t sink = 0;
    codes_gauss_newton_nonlinear::ResidualFn fn = [](const std::vector<double>& th){return std::vector<double>{th[0]*std::exp(th[1]*0.0)-2.5, th[0]*std::exp(th[1]*1.0)-1.6758001, th[0]*std::exp(th[1]*2.0)-1.1233224};};
    auto t0 = std::chrono::steady_clock::now();
    for (int it = 0; it < 200; ++it) {
        auto r = codes_gauss_newton_nonlinear::solve_levenberg_marquardt(fn, {1.5, -0.2}, 40, 1e-7); sink += r.steps;
    }
    auto t1 = std::chrono::steady_clock::now();
    double ns = std::chrono::duration<double, std::nano>(t1 - t0).count() / 200.0;
    std::cout << "gauss_newton_nonlinear ns=" << ns << " sink=" << sink << "\n";
    return 0;
}
