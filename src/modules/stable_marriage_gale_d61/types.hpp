#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include <string>
#include <array>
#include <functional>
#include <utility>

namespace codes_stable_marriage_gale_d61 {
struct MatchPair {
    int proposer;
    int receiver;
};

struct ModuleMeta {
    static constexpr const char* kSlug = "stable_marriage_gale_d61";
    int version = 1;
};
} // namespace codes_stable_marriage_gale_d61
