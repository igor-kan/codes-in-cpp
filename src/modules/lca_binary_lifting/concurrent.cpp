#include "interface.hpp"
#include <algorithm>
#include <thread>

namespace codes_lca_binary_lifting {
std::vector<std::size_t> parallel_lca_batch(const LcaIndex& idx, const std::vector<std::pair<std::size_t, std::size_t>>& pairs) {
    std::vector<std::size_t> out(pairs.size(), 0);
    std::vector<std::thread> workers;
    const std::size_t nt = std::min<std::size_t>(4, pairs.size());
    for (std::size_t t = 0; t < nt; ++t) {
        workers.emplace_back([&, t]() {
            for (std::size_t i = t; i < pairs.size(); i += nt) {
                out[i] = query_lca(idx, pairs[i].first, pairs[i].second);
            }
        });
    }
    for (auto& w : workers) w.join();
    return out;
}
} // namespace codes_lca_binary_lifting
