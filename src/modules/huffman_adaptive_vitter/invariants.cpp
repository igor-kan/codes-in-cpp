#include "interface.hpp"

namespace codes_huffman_adaptive_vitter {
Status verify_roundtrip_invariants(const std::vector<uint8_t>& input) {
    auto enc = adaptive_encode(input);
    if (validate_stream(enc) != Status::Ok) return Status::InvariantViolation;
    auto dec = adaptive_decode(enc);
    if (dec != input) return Status::InvariantViolation;
    return Status::Ok;
}
} // namespace codes_huffman_adaptive_vitter
