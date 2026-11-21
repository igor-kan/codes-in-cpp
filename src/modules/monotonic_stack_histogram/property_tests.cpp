#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_monotonic_stack_histogram;
    auto chks = parallel_checksum_batches({{1, 2, 3}, {4, 5, 6}});
    assert(chks.size() == 2 && chks[0] != chks[1]);
    std::vector<long long> bars = {3, 6, 5, 7, 4, 8, 1, 0};
    long long mx = largest_histogram_area(bars);
    assert(mx >= 8 && mx == 20);
    return 0;
}
