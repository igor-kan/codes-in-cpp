#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_bron_kerbosch_clique_d61;
    auto chks = parallel_checksum_batches({{1, 2, 3}, {4, 5, 6}});
    assert(chks.size() == 2 && chks[0] != chks[1]);
    BronKerbosch bk(7);
    for (int i = 0; i < 7; ++i) {
        for (int j = i + 1; j < 7; ++j) {
            if (((i * 5 + j * 3) % 4) != 0) bk.add_edge(i, j);
        }
    }
    auto cliques = bk.maximal_cliques();
    assert(!cliques.empty());
    for (const auto& clique : cliques) {
        assert(!clique.empty());
        for (std::size_t a = 0; a < clique.size(); ++a) {
            for (std::size_t b = a + 1; b < clique.size(); ++b) {
                assert(bk.adjacent(clique[a], clique[b]));
            }
        }
        for (int v = 0; v < 7; ++v) {
            bool member = false;
            for (int u : clique) {
                if (u == v) member = true;
            }
            if (member) continue;
            bool joins_all = true;
            for (int u : clique) {
                if (!bk.adjacent(v, u)) {
                    joins_all = false;
                    break;
                }
            }
            assert(!joins_all);
        }
    }
    for (std::size_t i = 0; i < cliques.size(); ++i) {
        for (std::size_t j = i + 1; j < cliques.size(); ++j) {
            bool same = cliques[i].size() == cliques[j].size();
            for (int u : cliques[i]) {
                bool found = false;
                for (int w : cliques[j]) {
                    if (w == u) found = true;
                }
                if (!found) same = false;
            }
            assert(!same);
        }
    }
    int brute_largest = 0;
    for (int mask = 1; mask < (1 << 7); ++mask) {
        bool is_clique = true;
        for (int i = 0; i < 7 && is_clique; ++i) {
            if ((mask & (1 << i)) == 0) continue;
            for (int j = i + 1; j < 7; ++j) {
                if ((mask & (1 << j)) != 0 && !bk.adjacent(i, j)) {
                    is_clique = false;
                    break;
                }
            }
        }
        if (is_clique) {
            int bits = 0;
            for (int v = 0; v < 7; ++v) {
                if ((mask & (1 << v)) != 0) ++bits;
            }
            if (bits > brute_largest) brute_largest = bits;
        }
    }
    assert(bk.summary().largest == brute_largest);
    BronKerbosch star(6);
    for (int v = 1; v < 6; ++v) star.add_edge(0, v);
    auto star_summary = star.summary();
    assert(star_summary.count == 5 && star_summary.largest == 2);
    BronKerbosch complete(6);
    for (int u = 0; u < 6; ++u) {
        for (int v = u + 1; v < 6; ++v) complete.add_edge(u, v);
    }
    auto complete_summary = complete.summary();
    assert(complete_summary.count == 1 && complete_summary.largest == 6);
    BronKerbosch isolated(5);
    auto isolated_summary = isolated.summary();
    assert(isolated_summary.count == 5 && isolated_summary.largest == 1);
    return 0;
}
