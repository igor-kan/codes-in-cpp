#include "interface.hpp"
#include <cassert>

int main() {
    using namespace codes_heavy_light_euler_tour;
    EulerSubtreeEngine eng(5, {{0,1},{0,2},{1,3},{1,4}}, {10, 20, 30, 40, 50});
    verify_euler_brackets(eng.tour());
    assert(eng.subtree_sum(0) == 150);
    assert(eng.subtree_sum(1) == 110);
    eng.add_point(4, 15);
    assert(eng.subtree_sum(1) == 125);
    assert(eng.subtree_sum(0) == 165);
    return 0;
}
