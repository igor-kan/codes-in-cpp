#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_lcs_string_reconstruct_d59;
    auto chks = parallel_checksum_batches({{1, 2, 3}, {4, 5, 6}});
    assert(chks.size() == 2 && chks[0] != chks[1]);
    assert(reconstruct_lcs("ABC", "DEF").empty());
    return 0;
}
