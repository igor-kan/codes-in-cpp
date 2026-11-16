#include "interface.hpp"
#include <chrono>
#include <iostream>

int main() {
    std::size_t sink = 0;
    std::vector<codes_interval_scheduling_weighted::WeightedJob> js; for(std::size_t i=0;i<256;++i) js.push_back({static_cast<int64_t>(i*2), static_cast<int64_t>(i*2+5), static_cast<int64_t>((i%17)+1), i});
    auto t0 = std::chrono::steady_clock::now();
    for (int it = 0; it < 200; ++it) {
        sink += static_cast<std::size_t>(codes_interval_scheduling_weighted::max_weight_dp_fast(js));
    }
    auto t1 = std::chrono::steady_clock::now();
    double ns = std::chrono::duration<double, std::nano>(t1 - t0).count() / 200.0;
    std::cout << "interval_scheduling_weighted ns=" << ns << " sink=" << sink << "\n";
    return 0;
}
