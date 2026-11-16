#include "interface.hpp"
#include <cassert>
#include <cstdint>

int main() {
    using namespace codes_huffman_adaptive_vitter;
    uint64_t rng = 0x777788889999AAAAULL;
    std::vector<std::vector<uint8_t>> chunks(8);
    for (auto& c : chunks) {
        for (int i = 0; i < 120; ++i) {
            rng = rng * 6364136223846793005ULL + 1ULL;
            c.push_back(static_cast<uint8_t>('A' + ((rng >> 32) % 16)));
        }
    }
    auto encs = batch_encode(chunks);
    for (std::size_t i = 0; i < chunks.size(); ++i) {
        assert(adaptive_decode(encs[i]) == chunks[i]);
        assert(verify_roundtrip_invariants(chunks[i]) == Status::Ok);
    }
    return 0;
}
