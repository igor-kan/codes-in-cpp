#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include <string>
#include <array>
#include <functional>
#include <utility>

namespace codes_coin_change_ways_d57 {
struct CoinTargetMeta {
    int target = 0;
    long long mod_prime = 1000000007LL;
};

struct ModuleMeta {
    static constexpr const char* kSlug = "coin_change_ways_d57";
    int version = 1;
};
} // namespace codes_coin_change_ways_d57
