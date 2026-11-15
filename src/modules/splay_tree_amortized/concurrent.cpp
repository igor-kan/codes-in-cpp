#include "interface.hpp"
#include <algorithm>
#include <thread>

namespace codes_splay_tree_amortized {
std::vector<std::size_t> batch_count_hits(const std::vector<long long>& dict, const std::vector<std::vector<long long>>& queries) {
    std::vector<std::size_t> out(queries.size(), 0);
    std::vector<long long> sorted = dict;
    std::sort(sorted.begin(), sorted.end());
    sorted.erase(std::unique(sorted.begin(), sorted.end()), sorted.end());
    std::vector<std::thread> workers;
    const std::size_t nt = std::min<std::size_t>(4, queries.size());
    for (std::size_t t = 0; t < nt; ++t) {
        workers.emplace_back([&, t]() {
            SplayTree local;
            splay_insert_sorted_batch(local, sorted);
            for (std::size_t i = t; i < queries.size(); i += nt) {
                std::size_t hits = 0;
                for (long long k : queries[i]) if (splay_contains(local, k)) ++hits;
                out[i] = hits;
            }
        });
    }
    for (auto& w : workers) w.join();
    return out;
}
} // namespace codes_splay_tree_amortized
