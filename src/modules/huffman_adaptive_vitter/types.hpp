#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include <string>
#include <array>
#include <functional>
#include <utility>

namespace codes_huffman_adaptive_vitter {
struct AdaptiveNode {
    int parent = -1;
    int left = -1;
    int right = -1;
    int weight = 0;
    int symbol = -1; // -1 internal, -2 NYT, 0..255 leaf
};

struct EncodedStream {
    std::vector<uint8_t> bits;
    std::size_t orig_len = 0;
};
} // namespace codes_huffman_adaptive_vitter
