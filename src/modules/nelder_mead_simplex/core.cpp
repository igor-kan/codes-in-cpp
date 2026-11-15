#include "interface.hpp"
#include <algorithm>
#include <cmath>
#include <numeric>

namespace codes_nelder_mead_simplex {
NelderMeadResult nelder_mead_minimize(const std::function<double(const std::vector<double>&)>& fn, const std::vector<double>& x0, double step, const NelderMeadConfig& cfg) {
    const std::size_t d = x0.size();
    std::vector<std::vector<double>> simp(d + 1, x0);
    for (std::size_t i = 0; i < d; ++i) simp[i + 1][i] += step;

    std::vector<double> vals(d + 1);
    for (std::size_t i = 0; i <= d; ++i) vals[i] = fn(simp[i]);

    std::size_t it = 0;
    bool conv = false;
    for (; it < cfg.max_iter; ++it) {
        std::vector<std::size_t> ord(d + 1);
        std::iota(ord.begin(), ord.end(), 0);
        std::sort(ord.begin(), ord.end(), [&](std::size_t a, std::size_t b) { return vals[a] < vals[b]; });

        double span = vals[ord[d]] - vals[ord[0]];
        double diam = 0.0;
        for (std::size_t j = 0; j < d; ++j) diam = std::max(diam, std::abs(simp[ord[d]][j] - simp[ord[0]][j]));
        if (span < cfg.tol && diam < cfg.tol) { conv = true; break; }

        std::vector<double> cent(d, 0.0);
        for (std::size_t i = 0; i < d; ++i) {
            for (std::size_t j = 0; j < d; ++j) cent[j] += simp[ord[i]][j];
        }
        for (std::size_t j = 0; j < d; ++j) cent[j] /= static_cast<double>(d);

        std::vector<double> xr(d);
        for (std::size_t j = 0; j < d; ++j) xr[j] = cent[j] + cfg.alpha * (cent[j] - simp[ord[d]][j]);
        double fr = fn(xr);

        if (vals[ord[0]] <= fr && fr < vals[ord[d - 1]]) {
            simp[ord[d]] = std::move(xr);
            vals[ord[d]] = fr;
            continue;
        }
        if (fr < vals[ord[0]]) {
            std::vector<double> xe(d);
            for (std::size_t j = 0; j < d; ++j) xe[j] = cent[j] + cfg.gamma * (xr[j] - cent[j]);
            double fe = fn(xe);
            if (fe < fr) { simp[ord[d]] = std::move(xe); vals[ord[d]] = fe; }
            else         { simp[ord[d]] = std::move(xr); vals[ord[d]] = fr; }
            continue;
        }
        bool shrunk = false;
        if (fr < vals[ord[d]]) {
            std::vector<double> xc(d);
            for (std::size_t j = 0; j < d; ++j) xc[j] = cent[j] + cfg.rho * (xr[j] - cent[j]);
            double fc = fn(xc);
            if (fc <= fr) { simp[ord[d]] = std::move(xc); vals[ord[d]] = fc; }
            else shrunk = true;
        } else {
            std::vector<double> xc(d);
            for (std::size_t j = 0; j < d; ++j) xc[j] = cent[j] + cfg.rho * (simp[ord[d]][j] - cent[j]);
            double fc = fn(xc);
            if (fc < vals[ord[d]]) { simp[ord[d]] = std::move(xc); vals[ord[d]] = fc; }
            else shrunk = true;
        }
        if (shrunk) {
            const auto& best = simp[ord[0]];
            for (std::size_t i = 1; i <= d; ++i) {
                for (std::size_t j = 0; j < d; ++j) {
                    simp[ord[i]][j] = best[j] + cfg.sigma * (simp[ord[i]][j] - best[j]);
                }
                vals[ord[i]] = fn(simp[ord[i]]);
            }
        }
    }
    std::size_t best_i = static_cast<std::size_t>(std::min_element(vals.begin(), vals.end()) - vals.begin());
    return {simp[best_i], vals[best_i], it, conv};
}
} // namespace codes_nelder_mead_simplex
