#include "interface.hpp"
#include <algorithm>
#include <thread>

namespace codes_huffman_adaptive_vitter {
std::vector<EncodedStream> batch_encode(const std::vector<std::vector<uint8_t>>& chunks) {
    std::vector<EncodedStream> out(chunks.size());
    if (chunks.empty()) return out;
    std::size_t nt = std::min<std::size_t>(4, chunks.size());
    std::vector<std::thread> pool;
    for (std::size_t t = 0; t < nt; ++t) {
        pool.emplace_back([&, t]() {
            for (std::size_t i = t; i < chunks.size(); i += nt) {
                out[i] = adaptive_encode(chunks[i]);
            }
        });
    }
    for (auto& th : pool) th.join();
    return out;
}
} // namespace codes_huffman_adaptive_vitter
