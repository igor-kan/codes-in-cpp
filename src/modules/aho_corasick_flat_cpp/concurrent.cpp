#include "interface.hpp"
#include <thread>

namespace codes_aho_corasick_flat_cpp {
std::vector<int> parallel_scan_corpus(const std::vector<std::string>& patterns, const std::vector<std::string>& texts) {
    FlatAhoCorasick ac(patterns);
    std::vector<int> out(texts.size(), 0);
    std::size_t mid = texts.size() / 2;
    auto run = [&](std::size_t lo, std::size_t hi) {
        for (std::size_t i = lo; i < hi; ++i) out[i] = ac.count_matches(texts[i]);
    };
    std::thread t1(run, 0, mid);
    std::thread t2(run, mid, texts.size());
    t1.join();
    t2.join();
    return out;
}
} // namespace codes_aho_corasick_flat_cpp
