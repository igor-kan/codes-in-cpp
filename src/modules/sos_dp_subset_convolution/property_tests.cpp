#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_sos_dp_subset_convolution;
    auto chks = parallel_checksum_batches({{1, 2, 3}, {4, 5, 6}});
    assert(chks.size() == 2 && chks[0] != chks[1]);
    std::vector<long long> orig = {3, -1, 5, 2, 7, 0, -4, 6};
    auto inv = sos_mobius(sos_zeta(orig, 3), 3);
    assert(inv == orig);
    return 0;
}
