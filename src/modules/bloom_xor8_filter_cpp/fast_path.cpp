#include "interface.hpp"

namespace codes_bloom_xor8_filter_cpp {
std::size_t xor8_fast_count_hits(const Xor8Filter& f, const std::vector<std::uint64_t>& probes) {
    std::size_t hits = 0;
    for (auto p : probes) {
        if (xor8_contains(f, p)) ++hits;
    }
    return hits;
}
} // namespace codes_bloom_xor8_filter_cpp
