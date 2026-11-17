#include "interface.hpp"
#include <cassert>

int main() {
    using namespace codes_fenwick_range_add_cpp;
    verify_dual_fenwick_oracle(12, {{0, 5, 4}, {3, 9, -2}, {4, 4, 7}, {0, 11, 1}});
    return 0;
}
