#include "interface.hpp"
#include <chrono>
#include <iostream>

int main() {
    using namespace codes_van_emde_boas_universe;
    FlatVebSet veb(1024); veb.insert(10); veb.insert(500);
    auto t0 = std::chrono::steady_clock::now();
    volatile std::int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        sink += veb.successor(10);
    }
    auto t1 = std::chrono::steady_clock::now();
    auto us = std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count();
    std::cout << "van_emde_boas_universe us=" << us << " sink=" << sink << "\n";
    return 0;
}
