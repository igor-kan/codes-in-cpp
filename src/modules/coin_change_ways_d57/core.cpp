#include "interface.hpp"
#include <algorithm>
#include <cmath>
#include <limits>
#include <numeric>
#include <queue>

namespace codes_coin_change_ways_d57 {

long long count_coin_combinations(const std::vector<int>& coins, int target) {
    if (target < 0) throw std::invalid_argument("negative target");
    const long long MOD = 1000000007LL;
    std::vector<long long> dp(target + 1, 0);
    dp[0] = 1;
    for (int c : coins) {
        if (c <= 0) throw std::invalid_argument("positive denominations required");
        for (int s = c; s <= target; ++s) {
            dp[s] = (dp[s] + dp[s - c]) % MOD;
        }
    }
    return dp[target];
}

} // namespace codes_coin_change_ways_d57
