#include "interface.hpp"

namespace codes_huffman_adaptive_vitter {
Status validate_stream(const EncodedStream& stream) {
    if (stream.orig_len > 0 && stream.bits.empty()) return Status::InvalidInput;
    return Status::Ok;
}
} // namespace codes_huffman_adaptive_vitter
