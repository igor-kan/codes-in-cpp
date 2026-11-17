#include "interface.hpp"
#include <cassert>

int main() {
    using namespace codes_sliding_window_median_heaps;
    std::vector<std::int64_t> s1(50), s2(50);
    for (int i = 0; i < 50; ++i) { s1[i] = (i * 19) % 13; s2[i] = 50 - i; }
    auto out = parallel_median_streams({s1, s2}, 6);
    verify_medians_oracle(s1, 6, out[0]);
    verify_medians_oracle(s2, 6, out[1]);
    return 0;
}
