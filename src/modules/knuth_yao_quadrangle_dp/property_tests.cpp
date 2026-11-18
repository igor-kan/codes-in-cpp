#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_knuth_yao_quadrangle_dp;
    auto chks = parallel_checksum_batches({{1, 2, 3}, {4, 5, 6}});
    assert(chks.size() == 2 && chks[0] != chks[1]);
    auto res = solve_obst_knuth({10, 12, 20});
    assert(res.min_cost == 72);
    return 0;
}
