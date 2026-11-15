#include "interface.hpp"
#include <cassert>
#include <numeric>

int main() {
    using namespace codes_persistent_seg_tree;
    std::vector<std::vector<long long>> history;
    std::vector<long long> cur(32, 0);
    history.push_back(cur);
    auto pst = pst_create(cur);
    for (std::size_t step = 0; step < 30; ++step) {
        std::size_t pos = (step * 11 + 5) % 32;
        long long delta = static_cast<long long>((step % 7) - 2);
        cur[pos] += delta;
        history.push_back(cur);
        pst_update(pst, step, pos, delta);
    }
    for (std::size_t v = 0; v < history.size(); ++v) {
        assert(verify_pst_node_sums(pst, pst.roots[v], 0, 31) == Status::Ok);
        assert(pst_query_sum(pst, v, 3, 25) == std::accumulate(history[v].begin() + 3, history[v].begin() + 26, 0LL));
    }
    return 0;
}
