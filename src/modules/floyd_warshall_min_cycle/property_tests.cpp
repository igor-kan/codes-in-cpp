#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_floyd_warshall_min_cycle;
    auto chks = parallel_checksum_batches({{1, 2, 3}, {4, 5, 6}});
    assert(chks.size() == 2 && chks[0] != chks[1]);
    std::vector<std::vector<long long>> neg = {{0, 1}, {-2, 0}};
    assert(floyd_warshall_solve(neg).has_negative_cycle);
    return 0;
}
