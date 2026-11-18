#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_fractional_cascading_grid;
    auto chks = parallel_checksum_batches({{1, 2, 3}, {4, 5, 6}});
    assert(chks.size() == 2 && chks[0] != chks[1]);
    FractionalCascader fc({{1, 10}, {2, 20}});
    assert((fc.query_lower_bounds(15) == std::vector<std::int64_t>{-1, 20}));
    return 0;
}
