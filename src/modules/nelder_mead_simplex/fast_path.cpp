#include "interface.hpp"

namespace codes_nelder_mead_simplex {
double rosenbrock_2d(const std::vector<double>& x) {
    double t1 = 1.0 - x[0];
    double t2 = x[1] - x[0] * x[0];
    return t1 * t1 + 100.0 * t2 * t2;
}
} // namespace codes_nelder_mead_simplex
