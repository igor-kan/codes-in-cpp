#include "interface.hpp"
#include <thread>

namespace codes_fenwick_range_add_cpp {
std::vector<std::int64_t> parallel_verify_shards(int n, const std::vector<std::vector<RangeAddOp>>& shards) {
    std::vector<std::int64_t> out(shards.size(), 0);
    std::size_t mid = shards.size() / 2;
    auto run = [&](std::size_t lo, std::size_t hi) {
        for (std::size_t i = lo; i < hi; ++i) {
            DualFenwick df(n);
            fast_apply_batch(df, shards[i]);
            out[i] = df.range_sum(0, n - 1);
        }
    };
    std::thread t1(run, 0, mid);
    std::thread t2(run, mid, shards.size());
    t1.join();
    t2.join();
    return out;
}
} // namespace codes_fenwick_range_add_cpp
