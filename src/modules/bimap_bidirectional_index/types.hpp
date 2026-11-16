#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include <string>
#include <array>
#include <functional>
#include <utility>

namespace codes_bimap_bidirectional_index {
struct BiMapStats {
    std::size_t count = 0;
    std::size_t rejected_conflicts = 0;
};

struct BiMapSlot {
    int64_t key = 0;
    std::string val;
    bool occupied = false;
};

struct IntStrBiMap {
    std::vector<BiMapSlot> fwd_slots;
    std::vector<std::pair<std::string, int64_t>> rev_pairs;
    std::size_t count = 0;
    std::size_t conflicts = 0;
};
} // namespace codes_bimap_bidirectional_index
