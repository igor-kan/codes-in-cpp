#include "interface.hpp"
#include <cassert>

int main() {
    using namespace codes_heavy_light_euler_tour;
    auto res = parallel_subtree_queries(5, {{0,1},{1,2},{2,3},{3,4}}, {1, 2, 3, 4, 5}, {0, 2, 4});
    assert((res == std::vector<std::int64_t>{15, 12, 5}));
    return 0;
}
