#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_tarjan_bridge_bcc_cpp;
    validate_problem_size(1);
    auto bs = find_bridges(5, {{0,1},{1,2},{2,0},{2,3},{3,4}});
    assert((bs == std::vector<std::pair<int, int>>{{2, 3}, {3, 4}}));
    verify_module_postcondition(true, "unit ok");
    return 0;
}
