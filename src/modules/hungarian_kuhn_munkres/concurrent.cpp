#include "interface.hpp"
#include <algorithm>
#include <thread>

namespace codes_hungarian_kuhn_munkres {
std::vector<AssignmentResult> parallel_solve_assignments(std::size_t n, const std::vector<std::vector<long long>>& matrices) {
    std::vector<AssignmentResult> out(matrices.size());
    std::vector<std::thread> workers;
    const std::size_t nt = std::min<std::size_t>(4, matrices.size());
    for (std::size_t t = 0; t < nt; ++t) {
        workers.emplace_back([&, t]() {
            for (std::size_t i = t; i < matrices.size(); i += nt) {
                out[i] = solve_hungarian(n, n, matrices[i]);
            }
        });
    }
    for (auto& w : workers) w.join();
    return out;
}
} // namespace codes_hungarian_kuhn_munkres
