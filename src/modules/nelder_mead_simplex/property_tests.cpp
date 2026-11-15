#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_nelder_mead_simplex;
    auto bowl = [](const std::vector<double>& x) {
        double s = 0.0;
        for (std::size_t i = 0; i < x.size(); ++i) {
            double d = x[i] - static_cast<double>(i + 1);
            s += (i + 1) * d * d;
        }
        return s;
    };
    NelderMeadConfig cfg;
    cfg.max_iter = 3000;
    std::vector<double> x0 = {-2.0, 0.0, 5.0};
    auto r = nelder_mead_minimize(bowl, x0, 0.5, cfg);
    assert(r.best_f < 1e-8);
    assert(verify_descent_from_start(bowl, x0, r) == Status::Ok);
    return 0;
}
