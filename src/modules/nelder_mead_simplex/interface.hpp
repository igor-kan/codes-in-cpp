#pragma once
#include "types.hpp"
#include "errors.hpp"

namespace codes_nelder_mead_simplex {
NelderMeadResult nelder_mead_minimize(const std::function<double(const std::vector<double>&)>& fn, const std::vector<double>& x0, double step, const NelderMeadConfig& cfg);
Status validate_nm_config(const std::vector<double>& x0, const NelderMeadConfig& cfg);
double rosenbrock_2d(const std::vector<double>& x);
std::vector<NelderMeadResult> parallel_multistart_nm(const std::vector<std::vector<double>>& starts);
Status verify_descent_from_start(const std::function<double(const std::vector<double>&)>& fn, const std::vector<double>& x0, const NelderMeadResult& res);
} // namespace codes_nelder_mead_simplex
