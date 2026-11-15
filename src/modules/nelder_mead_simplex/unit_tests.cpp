#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_nelder_mead_simplex;
    NelderMeadConfig cfg;
    cfg.max_iter = 4000;
    cfg.tol = 1e-10;
    std::vector<double> x0 = {-1.2, 1.0};
    assert(validate_nm_config(x0, cfg) == Status::Ok);
    auto r = nelder_mead_minimize(rosenbrock_2d, x0, 0.2, cfg);
    assert(r.converged);
    assert(std::abs(r.best_x[0] - 1.0) < 1e-4 && std::abs(r.best_x[1] - 1.0) < 1e-4);
    assert(verify_descent_from_start(rosenbrock_2d, x0, r) == Status::Ok);
    return 0;
}
