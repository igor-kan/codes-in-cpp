#include "interface.hpp"
#include <chrono>
#include <iostream>

int main() {
    using namespace codes_treap_implicit_rev_d58;
    std::vector<long long> b_a = {1, 2, 3, 4, 5, 6};
    auto t0 = std::chrono::steady_clock::now();
    volatile std::int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        reverse_subarray_twice_check(b_a, 1, 4); sink += subarray_sum(b_a, 0, 5);
    }
    auto t1 = std::chrono::steady_clock::now();
    auto us = std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count();
    std::cout << "treap_implicit_rev_d58 us=" << us << " sink=" << sink << "\n";
    return 0;
}
