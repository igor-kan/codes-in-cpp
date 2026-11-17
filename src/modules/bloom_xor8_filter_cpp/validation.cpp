#include "interface.hpp"

namespace codes_bloom_xor8_filter_cpp {
void validate_unique_keys(const std::vector<std::uint64_t>& keys) {
    if (keys.empty()) throw std::invalid_argument("Xor8 filter requires at least one key");
}
} // namespace codes_bloom_xor8_filter_cpp
