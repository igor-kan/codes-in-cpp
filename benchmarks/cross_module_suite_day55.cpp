// Cross-module integration & throughput driver for Day 55 `codes-in-cpp` modules.
#include "../src/modules/johnsons_reweight_apsp/interface.hpp"
#include "../src/modules/hungarian_min_assign_cpp/interface.hpp"
#include "../src/modules/convex_hull_trick_deque/interface.hpp"
#include "../src/modules/persistent_segtree_kth/interface.hpp"
#include "../src/modules/tarjan_bridge_bcc_cpp/interface.hpp"
#include <chrono>
#include <cstdint>
#include <iostream>

int main() {
    auto t0 = std::chrono::steady_clock::now();
    std::int64_t sink = 0;
    codes_johnsons_reweight_apsp::validate_problem_size(16); sink += codes_johnsons_reweight_apsp::fast_checksum_span({5, 6, 7, 1});
    codes_hungarian_min_assign_cpp::validate_problem_size(16); sink += codes_hungarian_min_assign_cpp::fast_checksum_span({5, 6, 7, 2});
    codes_convex_hull_trick_deque::validate_problem_size(16); sink += codes_convex_hull_trick_deque::fast_checksum_span({5, 6, 7, 3});
    codes_persistent_segtree_kth::validate_problem_size(16); sink += codes_persistent_segtree_kth::fast_checksum_span({5, 6, 7, 4});
    codes_tarjan_bridge_bcc_cpp::validate_problem_size(16); sink += codes_tarjan_bridge_bcc_cpp::fast_checksum_span({5, 6, 7, 5});
    auto t1 = std::chrono::steady_clock::now();
    auto us = std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count();
    std::cout << "codes-in-cpp day55 cross-module suite us=" << us << " sink=" << sink << "\n";
    return sink != 0 ? 0 : 1;
}
