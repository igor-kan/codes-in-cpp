#include "interface.hpp"
#include <numeric>
#include <thread>

namespace codes_treap_implicit_rope {
std::vector<long long> parallel_chunk_sums(const std::vector<std::vector<long long>>& seqs) {
    std::vector<long long> out(seqs.size(), 0);
    std::vector<std::thread> workers;
    const std::size_t nt = std::min<std::size_t>(4, seqs.size());
    for (std::size_t t = 0; t < nt; ++t) {
        workers.emplace_back([&, t]() {
            for (std::size_t i = t; i < seqs.size(); i += nt) {
                ImplicitTreapArena arena;
                build_linear_fast(arena, seqs[i]);
                out[i] = query_sum(arena, 0, seqs[i].size());
            }
        });
    }
    for (auto& w : workers) w.join();
    return out;
}
} // namespace codes_treap_implicit_rope
