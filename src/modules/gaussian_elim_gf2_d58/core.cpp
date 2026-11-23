#include "interface.hpp"
#include <algorithm>
#include <cmath>
#include <limits>
#include <numeric>
#include <queue>

namespace codes_gaussian_elim_gf2_d58 {

uint64_t gf2_max_subset_xor(const std::vector<uint64_t>& nums) {
    uint64_t basis[62] = {};
    for (uint64_t x : nums) {
        for (int b = 60; b >= 0; --b) {
            if (!((x >> b) & 1ULL)) continue;
            if (!basis[b]) { basis[b] = x; break; }
            x ^= basis[b];
        }
    }
    uint64_t ans = 0;
    for (int b = 60; b >= 0; --b) {
        if ((ans ^ basis[b]) > ans) ans ^= basis[b];
    }
    return ans;
}

int gf2_basis_rank(const std::vector<uint64_t>& nums) {
    uint64_t basis[62] = {};
    int r = 0;
    for (uint64_t x : nums) {
        for (int b = 60; b >= 0; --b) {
            if (!((x >> b) & 1ULL)) continue;
            if (!basis[b]) { basis[b] = x; ++r; break; }
            x ^= basis[b];
        }
    }
    return r;
}

} // namespace codes_gaussian_elim_gf2_d58
