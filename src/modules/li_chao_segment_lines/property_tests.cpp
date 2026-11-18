#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_li_chao_segment_lines;
    auto chks = parallel_checksum_batches({{1, 2, 3}, {4, 5, 6}});
    assert(chks.size() == 2 && chks[0] != chks[1]);
    LiChaoTree lc(64);
    lc.add_line(3, 0); lc.add_line(1, 20);
    assert(lc.query(5) == 15 && lc.query(15) == 35);
    return 0;
}
