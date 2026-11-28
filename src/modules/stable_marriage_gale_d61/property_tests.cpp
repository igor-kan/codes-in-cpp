#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_stable_marriage_gale_d61;
    auto chks = parallel_checksum_batches({{1, 2, 3}, {4, 5, 6}});
    assert(chks.size() == 2 && chks[0] != chks[1]);
    for (int n = 3; n <= 6; ++n) {
        StableMarriage sm(n);
        std::vector<std::vector<int>> men_pref(static_cast<std::size_t>(n));
        std::vector<std::vector<int>> women_pref(static_cast<std::size_t>(n));
        int stride = (n % 2 == 0) ? (n - 1) : 2;
        for (int m = 0; m < n; ++m) {
            std::vector<int> order;
            for (int j = 0; j < n; ++j) order.push_back((j * stride + m) % n);
            men_pref[static_cast<std::size_t>(m)] = order;
            sm.set_proposer_preferences(m, order);
        }
        for (int w = 0; w < n; ++w) {
            std::vector<int> order;
            for (int j = 0; j < n; ++j) order.push_back((j * stride + 2 * w + 1) % n);
            women_pref[static_cast<std::size_t>(w)] = order;
            sm.set_receiver_preferences(w, order);
        }
        auto match = sm.solve();
        assert(static_cast<int>(match.size()) == n);
        std::vector<int> held(static_cast<std::size_t>(n), -1);
        for (int m = 0; m < n; ++m) {
            assert(match[static_cast<std::size_t>(m)] >= 0 && match[static_cast<std::size_t>(m)] < n);
            assert(held[static_cast<std::size_t>(match[static_cast<std::size_t>(m)])] < 0);
            held[static_cast<std::size_t>(match[static_cast<std::size_t>(m)])] = m;
        }
        assert(sm.is_stable(match));
        assert(static_cast<int>(sm.pairs(match).size()) == n);
        for (int m = 0; m < n; ++m) {
            int partner = match[static_cast<std::size_t>(m)];
            for (int candidate : men_pref[static_cast<std::size_t>(m)]) {
                if (candidate == partner) break;
                int other = held[static_cast<std::size_t>(candidate)];
                if (other < 0) continue;
                int rank_proposer = -1;
                int rank_other = -1;
                for (int j = 0; j < n; ++j) {
                    if (women_pref[static_cast<std::size_t>(candidate)][static_cast<std::size_t>(j)] == m) {
                        rank_proposer = j;
                    }
                    if (women_pref[static_cast<std::size_t>(candidate)][static_cast<std::size_t>(j)] == other) {
                        rank_other = j;
                    }
                }
                assert(rank_proposer >= 0 && rank_other >= 0);
                assert(!(rank_proposer < rank_other));
            }
        }
    }
    return 0;
}
