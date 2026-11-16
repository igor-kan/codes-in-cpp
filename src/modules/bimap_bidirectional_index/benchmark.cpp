#include "interface.hpp"
#include <chrono>
#include <iostream>

int main() {
    std::size_t sink = 0;
    auto bm = codes_bimap_bidirectional_index::make_bimap(); for(int64_t i=0;i<128;++i) codes_bimap_bidirectional_index::insert_pair(bm, i, "val_" + std::to_string(i)); std::string s;
    auto t0 = std::chrono::steady_clock::now();
    for (int it = 0; it < 200; ++it) {
        for(int64_t i=0;i<64;++i) if(codes_bimap_bidirectional_index::find_by_key(bm, i, s)) sink += s.size();
    }
    auto t1 = std::chrono::steady_clock::now();
    double ns = std::chrono::duration<double, std::nano>(t1 - t0).count() / 200.0;
    std::cout << "bimap_bidirectional_index ns=" << ns << " sink=" << sink << "\n";
    return 0;
}
