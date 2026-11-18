#include "interface.hpp"
#include <chrono>
#include <iostream>

int main() {
    using namespace codes_palindromic_tree_eertree;
    Eertree et("abacaba");
    auto t0 = std::chrono::steady_clock::now();
    volatile std::int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        sink += et.distinct_palindromes();
    }
    auto t1 = std::chrono::steady_clock::now();
    auto us = std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count();
    std::cout << "palindromic_tree_eertree us=" << us << " sink=" << sink << "\n";
    return 0;
}
