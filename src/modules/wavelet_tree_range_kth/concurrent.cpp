#include "interface.hpp"
#include <thread>

namespace codes_wavelet_tree_range_kth {
std::vector<int> parallel_range_kth(const std::vector<int>& data, int lo, int hi, const std::vector<std::array<int, 3>>& queries) {
    WaveletTree wt(data, lo, hi);
    std::vector<int> out(queries.size(), 0);
    std::size_t mid = queries.size() / 2;
    auto run = [&](std::size_t s, std::size_t e) {
        for (std::size_t i = s; i < e; ++i) out[i] = wt.range_kth(queries[i][0], queries[i][1], queries[i][2]);
    };
    std::thread t1(run, 0, mid);
    std::thread t2(run, mid, queries.size());
    t1.join();
    t2.join();
    return out;
}
} // namespace codes_wavelet_tree_range_kth
