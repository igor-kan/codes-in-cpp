#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_bk_tree_metric_d61;
    auto chks = parallel_checksum_batches({{1, 2, 3}, {4, 5, 6}});
    assert(chks.size() == 2 && chks[0] != chks[1]);
    BkTree bk;
    std::vector<std::string> words = {"alpha", "beta", "gamma", "delta", "epsilon", "zeta", "eta", "theta"};
    for (std::size_t i = 0; i < words.size(); ++i) bk.insert(words[i]);
    assert(bk.size() == static_cast<int>(words.size()));
    for (std::size_t i = 0; i < words.size(); ++i) {
        auto hits = bk.search(words[i], 0);
        assert(hits.size() == 1 && hits[0] == words[i]);
    }
    auto near = bk.search("alpha", 2);
    assert(!near.empty());
    return 0;
}
