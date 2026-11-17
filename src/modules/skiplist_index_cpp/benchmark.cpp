#include "interface.hpp"
#include <chrono>
#include <iostream>


int main() {
    using namespace codes_skiplist_index_cpp;
    SkipListIndex sl; for(int i=0;i<256;++i) sl.upsert((i*37)%256, i);
    auto t0 = std::chrono::steady_clock::now();
    volatile std::int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        std::int64_t v=0; if(sl.find(iter%256, v)) sink += v;
    }
    auto t1 = std::chrono::steady_clock::now();
    auto us = std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count();
    std::cout << "skiplist_index_cpp us=" << us << " sink=" << sink << "\n";
    return 0;
}
