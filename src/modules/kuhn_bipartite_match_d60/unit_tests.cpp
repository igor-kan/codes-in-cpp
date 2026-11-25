#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_kuhn_bipartite_match_d60;
    validate_problem_size(1);
    std::vector<BipartiteEdge> es = {{0,0},{0,1},{1,1},{2,0},{2,2}};
    assert(kuhn_max_matching(3, 3, es) == 3);
    verify_module_postcondition(true, "unit ok");
    return 0;
}
