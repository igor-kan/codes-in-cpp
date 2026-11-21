#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_li_chao_convex_line_tree;
    auto chks = parallel_checksum_batches({{1, 2, 3}, {4, 5, 6}});
    assert(chks.size() == 2 && chks[0] != chks[1]);
    LiChaoTree lc(16);
    std::vector<std::pair<long long, long long>> lines = {{3, 1}, {-2, 25}, {1, 8}};
    for (auto [m, b] : lines) lc.add_line(m, b);
    for (int x = 0; x <= 16; ++x) {
        long long brute = lines[0].first * x + lines[0].second;
        for (auto [m, b] : lines) brute = std::min(brute, m * x + b);
        assert(lc.query(x) == brute);
    }
    return 0;
}
