#include "interface.hpp"
#include <cassert>

int main() {
    using namespace codes_bloom_xor8_filter_cpp;
    std::vector<std::uint64_t> keys;
    for (std::uint64_t i = 0; i < 200; ++i) keys.push_back(i * 1000003ULL + 7);
    auto f = build_xor8_filter(keys);
    verify_xor8_no_false_negatives(f, keys);
    std::size_t fp = 0;
    for (std::uint64_t i = 0; i < 1000; ++i) {
        if (xor8_contains(f, i * 1000003ULL + 8)) ++fp;
    }
    assert(fp < 20);
    return 0;
}
