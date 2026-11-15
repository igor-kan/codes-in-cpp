#include "interface.hpp"
#include <chrono>
#include <cmath>
#include <cstddef>
#include <iostream>

int main() {
    std::size_t sink = 0;
    codes_treap_implicit_rope::ImplicitTreapArena a; std::vector<long long> v(512, 3); codes_treap_implicit_rope::build_linear_fast(a, v);
    auto t0 = std::chrono::steady_clock::now();
    for (int it = 0; it < 200; ++it) {
        codes_treap_implicit_rope::reverse_range(a, 50, 400); sink += static_cast<std::size_t>(codes_treap_implicit_rope::query_sum(a, 10, 300));
    }
    auto t1 = std::chrono::steady_clock::now();
    double ns = std::chrono::duration<double, std::nano>(t1 - t0).count() / 200.0;
    std::cout << "treap_implicit_rope ns=" << ns << " sink=" << sink << "\n";
    return 0;
}
