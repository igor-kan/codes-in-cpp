#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include <string>
#include <array>
#include <functional>
#include <utility>

namespace codes_bloom_xor8_filter_cpp {
struct Xor8Filter {
    std::uint64_t seed = 0;
    std::size_t block_len = 0;
    std::vector<std::uint8_t> fingerprints;
};
} // namespace codes_bloom_xor8_filter_cpp
