#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_heavy_light_path_d60;
    auto chks = parallel_checksum_batches({{1, 2, 3}, {4, 5, 6}});
    assert(chks.size() == 2 && chks[0] != chks[1]);
    TreeLcaSolver tr(4, {{0,1,2},{1,2,3},{2,3,4}});
    assert(tr.path_dist(0, 3) == 9 && tr.path_dist(3, 0) == 9);
    return 0;
}
