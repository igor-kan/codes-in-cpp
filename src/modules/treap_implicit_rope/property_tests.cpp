#include "interface.hpp"
#include <algorithm>
#include <cassert>
#include <numeric>

int main() {
    using namespace codes_treap_implicit_rope;
    std::vector<long long> ref(40);
    std::iota(ref.begin(), ref.end(), 1LL);
    ImplicitTreapArena a;
    build_linear_fast(a, ref);
    assert(verify_treap_invariants(a, a.root) == Status::Ok);
    for (int step = 0; step < 35; ++step) {
        std::size_t l = static_cast<std::size_t>((step * 7) % 30);
        std::size_t r = l + 1 + static_cast<std::size_t>((step * 5) % (40 - l));
        reverse_range(a, l, r);
        std::reverse(ref.begin() + static_cast<long>(l), ref.begin() + static_cast<long>(r));
        assert(query_sum(a, l, r) == std::accumulate(ref.begin() + static_cast<long>(l), ref.begin() + static_cast<long>(r), 0LL));
    }
    std::vector<long long> got;
    to_vector(a, a.root, got);
    assert(got == ref);
    assert(verify_treap_invariants(a, a.root) == Status::Ok);
    return 0;
}
