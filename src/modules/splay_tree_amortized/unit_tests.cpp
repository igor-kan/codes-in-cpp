#include "interface.hpp"
#include <cassert>
#include <limits>

int main() {
    using namespace codes_splay_tree_amortized;
    SplayTree t;
    assert(splay_insert(t, 50));
    assert(splay_insert(t, 20));
    assert(splay_insert(t, 80));
    assert(splay_insert(t, 35));
    assert(!splay_insert(t, 20));
    assert(t.pool[static_cast<std::size_t>(t.root)].key == 20);
    assert(splay_contains(t, 35));
    assert(t.pool[static_cast<std::size_t>(t.root)].key == 35);
    long long k2 = 0;
    assert(kth_element(t, 2, k2) && k2 == 50);
    assert(splay_erase(t, 35));
    assert(!splay_contains(t, 35));
    assert(verify_splay_bst(t, t.root, std::numeric_limits<long long>::min(), std::numeric_limits<long long>::max()) == Status::Ok);
    return 0;
}
