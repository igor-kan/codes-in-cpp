#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_van_emde_boas_universe;
    auto chks = parallel_checksum_batches({{1, 2, 3}, {4, 5, 6}});
    assert(chks.size() == 2 && chks[0] != chks[1]);
    FlatVebSet veb(4096);
    for (int x = 10; x <= 4000; x += 100) veb.insert(x);
    assert(veb.successor(205) == 210 && veb.predecessor(205) == 110);
    return 0;
}
