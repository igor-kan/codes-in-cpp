#include "interface.hpp"

namespace codes_gauss_newton_nonlinear {
std::vector<double> assemble_jtj_symmetric(const std::vector<double>& jac, std::size_t m, std::size_t p) {
    std::vector<double> hmat(p * p, 0.0);
    for (std::size_t j = 0; j < p; ++j) {
        for (std::size_t k = j; k < p; ++k) {
            double s = 0.0;
            for (std::size_t i = 0; i < m; ++i) s += jac[i * p + j] * jac[i * p + k];
            hmat[j * p + k] = s;
            hmat[k * p + j] = s;
        }
    }
    return hmat;
}
} // namespace codes_gauss_newton_nonlinear
