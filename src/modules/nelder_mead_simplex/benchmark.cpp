#include "interface.hpp"
#include <chrono>
#include <cmath>
#include <cstddef>
#include <iostream>

int main() {
    std::size_t sink = 0;
    codes_nelder_mead_simplex::NelderMeadConfig cfg; cfg.max_iter=300;
    auto t0 = std::chrono::steady_clock::now();
    for (int it = 0; it < 200; ++it) {
        auto r = codes_nelder_mead_simplex::nelder_mead_minimize(codes_nelder_mead_simplex::rosenbrock_2d, {-0.5, 0.5}, 0.2, cfg); sink += r.iters;
    }
    auto t1 = std::chrono::steady_clock::now();
    double ns = std::chrono::duration<double, std::nano>(t1 - t0).count() / 200.0;
    std::cout << "nelder_mead_simplex ns=" << ns << " sink=" << sink << "\n";
    return 0;
}
