#include "interface.hpp"
#include <algorithm>
#include <cmath>

namespace codes_gauss_newton_nonlinear {
double compute_ssr(const std::vector<double>& r) {
    double s = 0.0;
    for (double v : r) s += v * v;
    return s;
}

bool solve_linear_system(std::vector<double> a, std::vector<double> b, std::vector<double>& x) {
    const std::size_t n = b.size();
    for (std::size_t i = 0; i < n; ++i) {
        std::size_t piv = i;
        for (std::size_t r = i + 1; r < n; ++r) {
            if (std::abs(a[r * n + i]) > std::abs(a[piv * n + i])) piv = r;
        }
        if (std::abs(a[piv * n + i]) < 1e-14) return false;
        if (piv != i) {
            for (std::size_t c = i; c < n; ++c) std::swap(a[i * n + c], a[piv * n + c]);
            std::swap(b[i], b[piv]);
        }
        for (std::size_t r = i + 1; r < n; ++r) {
            double f = a[r * n + i] / a[i * n + i];
            for (std::size_t c = i; c < n; ++c) a[r * n + c] -= f * a[i * n + c];
            b[r] -= f * b[i];
        }
    }
    x.assign(n, 0.0);
    for (std::size_t i = n; i-- > 0;) {
        double rhs = b[i];
        for (std::size_t c = i + 1; c < n; ++c) rhs -= a[i * n + c] * x[c];
        x[i] = rhs / a[i * n + i];
    }
    return true;
}

GaussNewtonResult solve_levenberg_marquardt(const ResidualFn& res_fn, std::vector<double> theta, std::size_t max_steps, double tol) {
    const std::size_t p = theta.size();
    std::vector<double> r = res_fn(theta);
    const std::size_t m = r.size();
    double ssr = compute_ssr(r);
    double lambda = 1e-3;
    std::size_t step = 0;
    bool conv = false;

    for (; step < max_steps; ++step) {
        std::vector<double> jac(m * p, 0.0);
        for (std::size_t j = 0; j < p; ++j) {
            double h = 1e-6 * std::max(1.0, std::abs(theta[j]));
            std::vector<double> tp = theta;
            tp[j] += h;
            auto rp = res_fn(tp);
            for (std::size_t i = 0; i < m; ++i) jac[i * p + j] = (rp[i] - r[i]) / h;
        }
        std::vector<double> hmat(p * p, 0.0), grad(p, 0.0);
        for (std::size_t j = 0; j < p; ++j) {
            for (std::size_t k = 0; k < p; ++k) {
                double s = 0.0;
                for (std::size_t i = 0; i < m; ++i) s += jac[i * p + j] * jac[i * p + k];
                hmat[j * p + k] = s;
            }
            double g = 0.0;
            for (std::size_t i = 0; i < m; ++i) g += jac[i * p + j] * r[i];
            grad[j] = -g;
        }
        bool accepted = false;
        for (int tries = 0; tries < 12; ++tries) {
            std::vector<double> damped = hmat;
            for (std::size_t j = 0; j < p; ++j) damped[j * p + j] += lambda * std::max(1.0, hmat[j * p + j]);
            std::vector<double> delta;
            if (!solve_linear_system(damped, grad, delta)) { lambda *= 10.0; continue; }
            std::vector<double> cand(p);
            double dnorm = 0.0;
            for (std::size_t j = 0; j < p; ++j) { cand[j] = theta[j] + delta[j]; dnorm = std::max(dnorm, std::abs(delta[j])); }
            auto rc = res_fn(cand);
            double ssr_c = compute_ssr(rc);
            if (ssr_c <= ssr) {
                theta = std::move(cand);
                r = std::move(rc);
                ssr = ssr_c;
                lambda = std::max(1e-9, lambda * 0.3);
                accepted = true;
                if (dnorm < tol) conv = true;
                break;
            }
            lambda *= 4.0;
        }
        if (conv || !accepted) break;
    }
    return {theta, ssr, step, conv};
}
} // namespace codes_gauss_newton_nonlinear
