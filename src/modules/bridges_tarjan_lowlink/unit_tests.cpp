#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_bridges_tarjan_lowlink;
    validate_problem_size(1);
    auto br = find_undirected_bridges(5, {{0, 1}, {1, 2}, {2, 0}, {1, 3}, {3, 4}});
    assert((br == std::vector<std::pair<int, int>>{{1, 3}, {3, 4}}));
    verify_module_postcondition(true, "unit ok");
    return 0;
}
