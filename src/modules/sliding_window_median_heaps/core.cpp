#include "interface.hpp"
#include <set>

namespace codes_sliding_window_median_heaps {

std::vector<double> sliding_window_medians(const std::vector<std::int64_t>& nums, std::size_t k) {
    validate_window(nums.size(), k);
    std::multiset<std::int64_t> lo, hi;
    auto rebalance = [&]() {
        while (lo.size() > hi.size() + 1) {
            auto it = std::prev(lo.end());
            hi.insert(*it);
            lo.erase(it);
        }
        while (hi.size() > lo.size()) {
            auto it = hi.begin();
            lo.insert(*it);
            hi.erase(it);
        }
    };
    auto add_val = [&](std::int64_t x) {
        if (lo.empty() || x <= *lo.rbegin()) lo.insert(x);
        else hi.insert(x);
        rebalance();
    };
    auto remove_val = [&](std::int64_t x) {
        auto it = lo.find(x);
        if (it != lo.end()) lo.erase(it);
        else hi.erase(hi.find(x));
        rebalance();
    };
    std::vector<double> out;
    out.reserve(nums.size() - k + 1);
    for (std::size_t i = 0; i < nums.size(); ++i) {
        add_val(nums[i]);
        if (i >= k) remove_val(nums[i - k]);
        if (i + 1 >= k) {
            if (k % 2 == 1) out.push_back(static_cast<double>(*lo.rbegin()));
            else out.push_back((static_cast<double>(*lo.rbegin()) + static_cast<double>(*hi.begin())) * 0.5);
        }
    }
    return out;
}

} // namespace codes_sliding_window_median_heaps
