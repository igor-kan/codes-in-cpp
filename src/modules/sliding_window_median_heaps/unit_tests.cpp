#include "interface.hpp"
#include <cassert>

int main() {
    using namespace codes_sliding_window_median_heaps;
    std::vector<std::int64_t> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    auto m3 = sliding_window_medians(nums, 3);
    verify_medians_oracle(nums, 3, m3);
    auto m4 = sliding_window_medians(nums, 4);
    verify_medians_oracle(nums, 4, m4);
    return 0;
}
