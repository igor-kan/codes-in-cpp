#include "interface.hpp"
#include <cassert>

int main() {
    using namespace codes_lru_k_eviction_cache;
    LruKCache c = make_lruk(3);
    put_page(c, 1, 100);
    put_page(c, 1, 101); // hot: 2 hits
    put_page(c, 2, 200); // hot after next line
    int64_t val = 0;
    assert(get_page(c, 2, val) && val == 200);
    put_page(c, 10, 1);
    put_page(c, 11, 2); // sequential cold scan should evict cold 10, NOT hot 1 or 2!
    assert(get_page(c, 1, val) && val == 101);
    assert(get_page(c, 2, val) && val == 200);
    assert(cache_size(c) <= 3);
    assert(verify_lruk_invariants(c) == Status::Ok);
    return 0;
}
