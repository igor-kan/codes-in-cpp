#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_floyd_warshall_min_cycle;
    validate_problem_size(1);
    const long long INF = 1000000000000000LL;
    std::vector<std::vector<long long>> m = {{0, 3, INF}, {INF, 0, 4}, {1, INF, 0}};
    auto res = floyd_warshall_solve(m);
    assert(!res.has_negative_cycle && res.dist[0][2] == 7 && res.dist[1][0] == 5);
    verify_module_postcondition(true, "unit ok");
    return 0;
}
