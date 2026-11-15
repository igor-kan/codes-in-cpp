#include "interface.hpp"
#include <cassert>
#include <limits>
#include <set>

int main() {
    using namespace codes_splay_tree_amortized;
    SplayTree t;
    std::set<long long> ref;
    for (int i = 0; i < 60; ++i) {
        long long k = ((i * 37 + 13) % 41) - 20;
        assert(splay_insert(t, k) == ref.insert(k).second);
        if (i % 5 == 0) {
            long long del = ((i * 11 + 3) % 41) - 20;
            assert(splay_erase(t, del) == (ref.erase(del) > 0));
        }
    }
    assert(verify_splay_bst(t, t.root, std::numeric_limits<long long>::min(), std::numeric_limits<long long>::max()) == Status::Ok);
    std::size_t idx = 0;
    for (long long v : ref) {
        long long kv = 0;
        assert(kth_element(t, idx++, kv) && kv == v);
    }
    return 0;
}
