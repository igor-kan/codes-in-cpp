#include "interface.hpp"
#include <thread>

namespace codes_heavy_light_euler_tour {
std::vector<std::int64_t> parallel_subtree_queries(
    int n,
    const std::vector<std::pair<int, int>>& edges,
    const std::vector<std::int64_t>& init,
    const std::vector<int>& queries
) {
    EulerSubtreeEngine eng(n, edges, init);
    std::vector<std::int64_t> out(queries.size(), 0);
    std::size_t mid = queries.size() / 2;
    auto run = [&](std::size_t lo, std::size_t hi) {
        for (std::size_t i = lo; i < hi; ++i) out[i] = eng.subtree_sum(queries[i]);
    };
    std::thread t1(run, 0, mid);
    std::thread t2(run, mid, queries.size());
    t1.join();
    t2.join();
    return out;
}
} // namespace codes_heavy_light_euler_tour
