#include "interface.hpp"
#include <cassert>

int main() {
    using namespace codes_skiplist_index_cpp;
    std::vector<std::int64_t> ks;
    for (int i = 0; i < 64; ++i) ks.push_back(i * 3);
    auto cnts = parallel_lookup_counts(ks, {{0, 3, 6, 7}, {9, 12, 1000}});
    assert((cnts == std::vector<std::size_t>{3, 2}));
    return 0;
}
