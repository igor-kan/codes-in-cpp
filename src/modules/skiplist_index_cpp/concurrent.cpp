#include "interface.hpp"
#include <thread>

namespace codes_skiplist_index_cpp {
std::vector<std::size_t> parallel_lookup_counts(
    const std::vector<std::int64_t>& keys,
    const std::vector<std::vector<std::int64_t>>& probe_batches
) {
    SkipListIndex sl;
    for (std::size_t i = 0; i < keys.size(); ++i) sl.upsert(keys[i], static_cast<std::int64_t>(i));
    std::vector<std::size_t> out(probe_batches.size(), 0);
    std::size_t mid = probe_batches.size() / 2;
    auto run = [&](std::size_t lo, std::size_t hi) {
        for (std::size_t i = lo; i < hi; ++i) out[i] = fast_count_present(sl, probe_batches[i]);
    };
    std::thread t1(run, 0, mid);
    std::thread t2(run, mid, probe_batches.size());
    t1.join();
    t2.join();
    return out;
}
} // namespace codes_skiplist_index_cpp
