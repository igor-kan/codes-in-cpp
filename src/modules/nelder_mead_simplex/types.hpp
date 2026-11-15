#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include <string>
#include <array>
#include <functional>
#include <utility>

namespace codes_nelder_mead_simplex {
struct NelderMeadConfig {
    double alpha = 1.0;
    double gamma = 2.0;
    double rho = 0.5;
    double sigma = 0.5;
    double tol = 1e-9;
    std::size_t max_iter = 2000;
};

struct NelderMeadResult {
    std::vector<double> best_x;
    double best_f = 0.0;
    std::size_t iters = 0;
    bool converged = false;
};
} // namespace codes_nelder_mead_simplex
