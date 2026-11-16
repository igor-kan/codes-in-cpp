#include "interface.hpp"
#include <chrono>
#include <iostream>

int main() {
    std::size_t sink = 0;
    std::vector<uint8_t> raw(256); for(std::size_t i=0;i<256;++i) raw[i]=static_cast<uint8_t>('A'+(i%12));
    auto t0 = std::chrono::steady_clock::now();
    for (int it = 0; it < 200; ++it) {
        auto enc = codes_huffman_adaptive_vitter::adaptive_encode(raw); sink += enc.bits.size();
    }
    auto t1 = std::chrono::steady_clock::now();
    double ns = std::chrono::duration<double, std::nano>(t1 - t0).count() / 200.0;
    std::cout << "huffman_adaptive_vitter ns=" << ns << " sink=" << sink << "\n";
    return 0;
}
