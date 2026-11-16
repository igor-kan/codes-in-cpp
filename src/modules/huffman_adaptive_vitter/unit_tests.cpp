#include "interface.hpp"
#include <cassert>

int main() {
    using namespace codes_huffman_adaptive_vitter;
    std::string msg = "aardvark_banana_mississippi_adaptive_huffman_test_payload_aaaaabbbbbcccc";
    std::vector<uint8_t> raw(msg.begin(), msg.end());
    auto enc = adaptive_encode(raw);
    auto dec = adaptive_decode(enc);
    assert(dec == raw);
    assert(enc.bits.size() < raw.size() * 8);
    assert(verify_roundtrip_invariants(raw) == Status::Ok);
    return 0;
}
