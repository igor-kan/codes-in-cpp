#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include <string>
#include <array>
#include <functional>
#include <utility>

namespace codes_gauss_newton_nonlinear {
using ResidualFn = std::function<std::vector<double>(const std::vector<double>&)>;

struct GaussNewtonResult {
    std::vector<double> params;
    double final_ssr = 0.0;
    std::size_t steps = 0;
    bool converged = false;
};
} // namespace codes_gauss_newton_nonlinear
