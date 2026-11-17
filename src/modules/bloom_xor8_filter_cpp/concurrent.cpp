#include "interface.hpp"
#include <thread>

namespace codes_bloom_xor8_filter_cpp {
std::vector<std::size_t> parallel_xor8_probe(const Xor8Filter& f, const std::vector<std::vector<std::uint64_t>>& batches) {
    std::vector<std::size_t> out(batches.size(), 0);
    std::size_t mid = batches.size() / 2;
    auto run = [&](std::size_t lo, std::size_t hi) {
        for (std::size_t i = lo; i < hi; ++i) out[i] = xor8_fast_count_hits(f, batches[i]);
    };
    std::thread t1(run, 0, mid);
    std::thread t2(run, mid, batches.size());
    t1.join();
    t2.join();
    return out;
}
} // namespace codes_bloom_xor8_filter_cpp
