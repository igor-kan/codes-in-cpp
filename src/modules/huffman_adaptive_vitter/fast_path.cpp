#include "interface.hpp"

namespace codes_huffman_adaptive_vitter {
double compression_ratio_bits(const EncodedStream& s) {
    if (s.orig_len == 0) return 1.0;
    return static_cast<double>(s.bits.size()) / static_cast<double>(s.orig_len * 8);
}
} // namespace codes_huffman_adaptive_vitter
