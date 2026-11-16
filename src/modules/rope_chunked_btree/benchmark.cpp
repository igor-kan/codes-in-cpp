#include "interface.hpp"
#include <chrono>
#include <iostream>

int main() {
    std::size_t sink = 0;
    auto r = codes_rope_chunked_btree::rope_from_string(std::string(512, 'a'));
    auto t0 = std::chrono::steady_clock::now();
    for (int it = 0; it < 200; ++it) {
        sink += static_cast<std::size_t>(codes_rope_chunked_btree::rope_at(r, static_cast<std::size_t>(it) % 512));
    }
    auto t1 = std::chrono::steady_clock::now();
    double ns = std::chrono::duration<double, std::nano>(t1 - t0).count() / 200.0;
    std::cout << "rope_chunked_btree ns=" << ns << " sink=" << sink << "\n";
    return 0;
}
