#include "interface.hpp"
#include <chrono>
#include <iostream>

int main() {
    using namespace codes_manacher_pal_d60;
    std::string txt = "abcddcbaabacaba";
    auto t0 = std::chrono::steady_clock::now();
    volatile std::int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        auto sp = longest_palindrome_d60(txt);
    sink = sink + sp.length + sp.start;
    }
    auto t1 = std::chrono::steady_clock::now();
    auto us = std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count();
    std::cout << "manacher_pal_d60 us=" << us << " sink=" << sink << "\n";
    return 0;
}
