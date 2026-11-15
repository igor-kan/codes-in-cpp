#include "interface.hpp"
#include <chrono>
#include <cmath>
#include <cstddef>
#include <iostream>

int main() {
    std::size_t sink = 0;
    std::vector<long long> mat(30*30); for(std::size_t i=0;i<900;++i) mat[i]=static_cast<long long>((i*19+7)%100);
    auto t0 = std::chrono::steady_clock::now();
    for (int it = 0; it < 200; ++it) {
        sink += static_cast<std::size_t>(codes_hungarian_kuhn_munkres::solve_hungarian(30, 30, mat).min_cost);
    }
    auto t1 = std::chrono::steady_clock::now();
    double ns = std::chrono::duration<double, std::nano>(t1 - t0).count() / 200.0;
    std::cout << "hungarian_kuhn_munkres ns=" << ns << " sink=" << sink << "\n";
    return 0;
}
