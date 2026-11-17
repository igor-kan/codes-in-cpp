#include "interface.hpp"

namespace codes_bloom_xor8_filter_cpp {
void verify_xor8_no_false_negatives(const Xor8Filter& f, const std::vector<std::uint64_t>& keys) {
    if (f.fingerprints.size() != f.block_len * 3) throw std::logic_error("invalid Xor8 block alignment");
    for (auto k : keys) {
        if (!xor8_contains(f, k)) throw std::logic_error("false negative detected in Xor8 filter");
    }
}
} // namespace codes_bloom_xor8_filter_cpp
