#include "interface.hpp"
#include <cassert>

int main() {
    using namespace codes_skiplist_index_cpp;
    SkipListIndex sl;
    for (int i = 20; i >= 1; --i) sl.upsert(i * 10, i);
    verify_skiplist_sorted(sl);
    std::int64_t v = 0;
    assert(sl.find(120, v) && v == 12);
    assert(!sl.find(125, v));
    assert((sl.range_values(30, 60) == std::vector<std::int64_t>{3, 4, 5, 6}));
    return 0;
}
