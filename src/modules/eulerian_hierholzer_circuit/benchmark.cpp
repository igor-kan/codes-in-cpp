#include "interface.hpp"
#include <chrono>
#include <iostream>

int main() {
    using namespace codes_eulerian_hierholzer_circuit;
    std::vector<std::pair<int, int>> b_es = {{0, 1}, {1, 2}, {2, 0}};
    auto t0 = std::chrono::steady_clock::now();
    volatile std::int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        sink += static_cast<long long>(hierholzer_euler_circuit(3, b_es).size());
    }
    auto t1 = std::chrono::steady_clock::now();
    auto us = std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count();
    std::cout << "eulerian_hierholzer_circuit us=" << us << " sink=" << sink << "\n";
    return 0;
}
