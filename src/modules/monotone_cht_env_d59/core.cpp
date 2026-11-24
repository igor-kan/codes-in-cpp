#include "interface.hpp"
#include <algorithm>
#include <cmath>
#include <limits>
#include <numeric>
#include <queue>

namespace codes_monotone_cht_env_d59 {

bool MonotoneCht::bad(const ChtLine& l1, const ChtLine& l2, const ChtLine& l3) {
    return (__int128)(l2.b - l1.b) * (l2.m - l3.m) >= (__int128)(l3.b - l2.b) * (l1.m - l2.m);
}

void MonotoneCht::add_decreasing(long long m, long long b) {
    ChtLine ln{m, b};
    while (dq_.size() - head_ >= 2 && bad(dq_[dq_.size() - 2], dq_.back(), ln)) dq_.pop_back();
    dq_.push_back(ln);
}

long long MonotoneCht::query_increasing(long long x) {
    while (dq_.size() - head_ >= 2 && dq_[head_].m * x + dq_[head_].b >= dq_[head_ + 1].m * x + dq_[head_ + 1].b) ++head_;
    return dq_[head_].m * x + dq_[head_].b;
}

} // namespace codes_monotone_cht_env_d59
