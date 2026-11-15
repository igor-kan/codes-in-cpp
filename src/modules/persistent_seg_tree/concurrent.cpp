#include "interface.hpp"
#include <algorithm>
#include <thread>

namespace codes_persistent_seg_tree {
std::vector<long long> parallel_version_totals(const PersistentSegTree& pst) {
    std::vector<long long> totals(pst.roots.size(), 0);
    if (pst.n == 0 || pst.roots.empty()) return totals;
    std::vector<std::thread> workers;
    const std::size_t nt = std::min<std::size_t>(4, pst.roots.size());
    for (std::size_t t = 0; t < nt; ++t) {
        workers.emplace_back([&, t]() {
            for (std::size_t v = t; v < pst.roots.size(); v += nt) {
                totals[v] = pst.pool[static_cast<std::size_t>(pst.roots[v])].sum;
            }
        });
    }
    for (auto& w : workers) w.join();
    return totals;
}
} // namespace codes_persistent_seg_tree
