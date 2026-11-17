#include "interface.hpp"

namespace codes_aho_corasick_flat_cpp {
int fast_count_char_stream(const FlatAhoCorasick& ac, const char* data, std::size_t len) {
    const auto& tbl = ac.table();
    int state = 0;
    int total = 0;
    for (std::size_t i = 0; i < len; ++i) {
        char ch = data[i];
        if (ch < 'a' || ch > 'z') {
            state = 0;
            continue;
        }
        state = tbl[static_cast<std::size_t>(state)].next[static_cast<std::size_t>(ch - 'a')];
        total += tbl[static_cast<std::size_t>(state)].out_count;
    }
    return total;
}
} // namespace codes_aho_corasick_flat_cpp
