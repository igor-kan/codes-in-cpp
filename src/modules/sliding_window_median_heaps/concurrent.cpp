#include "interface.hpp"
#include <thread>

namespace codes_sliding_window_median_heaps {
std::vector<std::vector<double>> parallel_median_streams(
    const std::vector<std::vector<std::int64_t>>& streams,
    std::size_t k
) {
    std::vector<std::vector<double>> out(streams.size());
    std::size_t mid = streams.size() / 2;
    auto run = [&](std::size_t lo, std::size_t hi) {
        for (std::size_t i = lo; i < hi; ++i) out[i] = sliding_window_medians(streams[i], k);
    };
    std::thread t1(run, 0, mid);
    std::thread t2(run, mid, streams.size());
    t1.join();
    t2.join();
    return out;
}
} // namespace codes_sliding_window_median_heaps
