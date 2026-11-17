#include "interface.hpp"
#include <cassert>

int main() {
    using namespace codes_bloom_xor8_filter_cpp;
    std::vector<std::uint64_t> k1, k2;
    for (std::uint64_t i = 1; i <= 100; ++i) k1.push_back(i);
    for (std::uint64_t i = 101; i <= 200; ++i) k2.push_back(i);
    std::vector<std::uint64_t> both = k1;
    both.insert(both.end(), k2.begin(), k2.end());
    auto f = build_xor8_filter(both);
    auto hits = parallel_xor8_probe(f, {k1, k2});
    assert(hits[0] == 100 && hits[1] == 100);
    return 0;
}
