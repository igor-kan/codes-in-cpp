#include "interface.hpp"

namespace codes_coin_change_ways_d57 {

std::int64_t fast_checksum_span(const std::vector<std::int64_t>& xs) {
    std::int64_t acc = 0;
    for (std::int64_t v : xs) {
        acc = acc * 1315423911LL + v;
    }
    return acc;
}

} // namespace codes_coin_change_ways_d57
