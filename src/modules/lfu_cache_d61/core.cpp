#include "interface.hpp"
#include <algorithm>
#include <cmath>
#include <limits>
#include <numeric>
#include <queue>

namespace codes_lfu_cache_d61 {

LfuCache::LfuCache(std::size_t capacity) : cap_(capacity) {}
int LfuCache::find(std::int64_t key) const {
    for (std::size_t i = 0; i < keys_.size(); ++i) {
        if (keys_[i] == key) return static_cast<int>(i);
    }
    return -1;
}
bool LfuCache::get(std::int64_t key, std::int64_t& out) {
    int idx = find(key);
    if (idx < 0) return false;
    std::size_t pos = static_cast<std::size_t>(idx);
    out = vals_[pos];
    freq_[pos] += 1;
    tick_ += 1;
    stamp_[pos] = tick_;
    return true;
}
void LfuCache::put(std::int64_t key, std::int64_t value) {
    tick_ += 1;
    int idx = find(key);
    if (idx >= 0) {
        std::size_t pos = static_cast<std::size_t>(idx);
        vals_[pos] = value;
        freq_[pos] += 1;
        stamp_[pos] = tick_;
        return;
    }
    if (keys_.size() < cap_) {
        keys_.push_back(key);
        vals_.push_back(value);
        freq_.push_back(1);
        stamp_.push_back(tick_);
        return;
    }
    if (keys_.empty()) return;
    std::size_t victim = 0;
    for (std::size_t i = 1; i < keys_.size(); ++i) {
        if (freq_[i] < freq_[victim] || (freq_[i] == freq_[victim] && stamp_[i] < stamp_[victim])) {
            victim = i;
        }
    }
    keys_[victim] = key;
    vals_[victim] = value;
    freq_[victim] = 1;
    stamp_[victim] = tick_;
}
std::size_t LfuCache::size() const {
    return keys_.size();
}

} // namespace codes_lfu_cache_d61
