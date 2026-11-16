#include "interface.hpp"
#include <algorithm>
#include <thread>

namespace codes_damerau_levenshtein_osa {
std::vector<EditMetrics> batch_edit_distances(const std::vector<std::pair<std::string, std::string>>& pairs) {
    std::vector<EditMetrics> out(pairs.size());
    if (pairs.empty()) return out;
    std::size_t nt = std::min<std::size_t>(4, pairs.size());
    std::vector<std::thread> pool;
    for (std::size_t t = 0; t < nt; ++t) {
        pool.emplace_back([&, t]() {
            for (std::size_t i = t; i < pairs.size(); i += nt) {
                out[i].osa_distance = optimal_string_alignment(pairs[i].first, pairs[i].second);
                out[i].true_dl_distance = true_damerau_levenshtein(pairs[i].first, pairs[i].second);
            }
        });
    }
    for (auto& th : pool) th.join();
    return out;
}
} // namespace codes_damerau_levenshtein_osa
