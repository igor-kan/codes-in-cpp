#include "interface.hpp"
#include <cassert>

int main() {
    using namespace codes_treap_implicit_rope;
    ImplicitTreapArena a;
    for (int i = 0; i < 6; ++i) insert_at(a, static_cast<std::size_t>(i), i + 1);
    assert(query_sum(a, 1, 4) == 9);
    reverse_range(a, 1, 5); // [1, 5, 4, 3, 2, 6]
    std::vector<long long> out;
    to_vector(a, a.root, out);
    assert((out == std::vector<long long>{1, 5, 4, 3, 2, 6}));
    assert(query_sum(a, 0, 3) == 10);
    assert(verify_treap_invariants(a, a.root) == Status::Ok);
    assert(validate_range(a, 0, 7) == Status::OutOfBounds);
    return 0;
}
