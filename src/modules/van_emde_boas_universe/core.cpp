#include "interface.hpp"
#include <algorithm>
#include <cmath>
#include <limits>
#include <numeric>
#include <queue>

namespace codes_van_emde_boas_universe {

FlatVebSet::FlatVebSet(int universe) : u_(universe), words_((universe + 63) / 64, 0ULL) {}

void FlatVebSet::insert(int x) {
    if (x >= 0 && x < u_) words_[x >> 6] |= (1ULL << (x & 63));
}

void FlatVebSet::erase(int x) {
    if (x >= 0 && x < u_) words_[x >> 6] &= ~(1ULL << (x & 63));
}

bool FlatVebSet::contains(int x) const {
    return x >= 0 && x < u_ && ((words_[x >> 6] >> (x & 63)) & 1ULL) != 0ULL;
}

int FlatVebSet::successor(int x) const {
    int nxt = x + 1;
    if (nxt < 0) nxt = 0;
    if (nxt >= u_) return -1;
    int w = nxt >> 6, b = nxt & 63;
    std::uint64_t mask = words_[w] & (~0ULL << b);
    if (mask != 0ULL) return (w << 6) + __builtin_ctzll(mask);
    for (int i = w + 1; i < static_cast<int>(words_.size()); ++i) {
        if (words_[i] != 0ULL) return (i << 6) + __builtin_ctzll(words_[i]);
    }
    return -1;
}

int FlatVebSet::predecessor(int x) const {
    int prv = x - 1;
    if (prv < 0) return -1;
    if (prv >= u_) prv = u_ - 1;
    int w = prv >> 6, b = prv & 63;
    std::uint64_t mask = words_[w] & (b == 63 ? ~0ULL : ((1ULL << (b + 1)) - 1ULL));
    if (mask != 0ULL) return (w << 6) + (63 - __builtin_clzll(mask));
    for (int i = w - 1; i >= 0; --i) {
        if (words_[i] != 0ULL) return (i << 6) + (63 - __builtin_clzll(words_[i]));
    }
    return -1;
}

} // namespace codes_van_emde_boas_universe
