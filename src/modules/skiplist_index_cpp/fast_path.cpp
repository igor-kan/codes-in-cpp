#include "interface.hpp"

namespace codes_skiplist_index_cpp {
std::size_t fast_count_present(const SkipListIndex& sl, const std::vector<std::int64_t>& probes) {
    std::size_t hits = 0;
    std::int64_t tmp = 0;
    for (auto p : probes) {
        if (sl.find(p, tmp)) ++hits;
    }
    return hits;
}
} // namespace codes_skiplist_index_cpp
