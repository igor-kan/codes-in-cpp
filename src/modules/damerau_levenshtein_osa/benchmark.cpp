#include "interface.hpp"
#include <chrono>
#include <iostream>

int main() {
    std::size_t sink = 0;
    std::string a(64, 'a'), b(64, 'b'); a[3]='x'; b[4]='x';
    auto t0 = std::chrono::steady_clock::now();
    for (int it = 0; it < 200; ++it) {
        sink += codes_damerau_levenshtein_osa::true_damerau_levenshtein(a, b);
    }
    auto t1 = std::chrono::steady_clock::now();
    double ns = std::chrono::duration<double, std::nano>(t1 - t0).count() / 200.0;
    std::cout << "damerau_levenshtein_osa ns=" << ns << " sink=" << sink << "\n";
    return 0;
}
