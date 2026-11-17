#include "interface.hpp"
#include <cassert>

int main() {
    using namespace codes_wavelet_tree_range_kth;
    std::vector<int> a = {8, 2, 7, 3, 6, 4, 5, 1, 9, 0};
    auto res = parallel_range_kth(a, 0, 9, {{0, 5, 2}, {2, 8, 0}, {4, 10, 5}});
    assert((res == std::vector<int>{6, 1, 9}));
    return 0;
}
