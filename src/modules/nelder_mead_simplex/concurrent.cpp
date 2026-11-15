#include "interface.hpp"
#include <algorithm>
#include <thread>

namespace codes_nelder_mead_simplex {
std::vector<NelderMeadResult> parallel_multistart_nm(const std::vector<std::vector<double>>& starts) {
    std::vector<NelderMeadResult> out(starts.size());
    std::vector<std::thread> workers;
    const std::size_t nt = std::min<std::size_t>(4, starts.size());
    NelderMeadConfig cfg;
    for (std::size_t t = 0; t < nt; ++t) {
        workers.emplace_back([&, t]() {
            for (std::size_t i = t; i < starts.size(); i += nt) {
                out[i] = nelder_mead_minimize(rosenbrock_2d, starts[i], 0.25, cfg);
            }
        });
    }
    for (auto& w : workers) w.join();
    return out;
}
} // namespace codes_nelder_mead_simplex
