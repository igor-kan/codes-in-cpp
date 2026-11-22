#include "interface.hpp"
#include <chrono>
#include <iostream>

int main() {
    using namespace codes_kosaraju_2sat_solver_d57;
    std::vector<SatClause> b_cls = {{0,false,1,true},{1,false,2,false}};
    auto t0 = std::chrono::steady_clock::now();
    volatile std::int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        sink += solve_two_sat(3, b_cls).first ? 1 : 0;
    }
    auto t1 = std::chrono::steady_clock::now();
    auto us = std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count();
    std::cout << "kosaraju_2sat_solver_d57 us=" << us << " sink=" << sink << "\n";
    return 0;
}
