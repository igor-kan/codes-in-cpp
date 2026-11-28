#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_lfu_cache_d61;
    auto chks = parallel_checksum_batches({{1, 2, 3}, {4, 5, 6}});
    assert(chks.size() == 2 && chks[0] != chks[1]);
    LfuCache cache(3);
    for (std::int64_t k = 1; k <= 3; ++k) cache.put(k, k * 10);
    std::int64_t value = 0;
    assert(cache.get(1, value) && value == 10);
    assert(cache.get(1, value));
    assert(cache.get(2, value) && value == 20);
    cache.put(4, 40);
    std::int64_t miss = 0;
    assert(!cache.get(3, miss));
    assert(cache.get(4, miss) && miss == 40);
    assert(cache.size() == 3);
    return 0;
}
