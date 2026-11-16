#pragma once
#include "types.hpp"
#include "errors.hpp"

namespace codes_huffman_adaptive_vitter {
EncodedStream adaptive_encode(const std::vector<uint8_t>& input);
std::vector<uint8_t> adaptive_decode(const EncodedStream& stream);
Status validate_stream(const EncodedStream& stream);
std::vector<EncodedStream> batch_encode(const std::vector<std::vector<uint8_t>>& chunks);
Status verify_roundtrip_invariants(const std::vector<uint8_t>& input);
} // namespace codes_huffman_adaptive_vitter
