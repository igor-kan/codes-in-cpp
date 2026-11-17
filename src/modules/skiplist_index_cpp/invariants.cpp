#include "interface.hpp"

namespace codes_skiplist_index_cpp {
void verify_skiplist_sorted(const SkipListIndex& sl) {
    const auto& raw = sl.raw_nodes();
    int cur = raw[0].next[0];
    int seen = 0;
    std::int64_t prev = 0;
    bool has_prev = false;
    while (cur != -1) {
        if (has_prev && raw[static_cast<std::size_t>(cur)].key <= prev) {
            throw std::logic_error("skip list level-0 ordering violated");
        }
        prev = raw[static_cast<std::size_t>(cur)].key;
        has_prev = true;
        ++seen;
        cur = raw[static_cast<std::size_t>(cur)].next[0];
    }
    if (seen != sl.size()) throw std::logic_error("skip list size mismatch");
}
} // namespace codes_skiplist_index_cpp
