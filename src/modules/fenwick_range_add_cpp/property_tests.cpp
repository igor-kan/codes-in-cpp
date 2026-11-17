#include "interface.hpp"
#include <cassert>

int main() {
    using namespace codes_fenwick_range_add_cpp;
    auto res = parallel_verify_shards(10, {{{0, 4, 3}, {2, 7, 2}}, {{1, 8, 5}}});
    assert((res == std::vector<std::int64_t>{5 * 3 + 6 * 2, 8 * 5}));
    return 0;
}
