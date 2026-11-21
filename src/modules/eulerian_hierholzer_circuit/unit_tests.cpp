#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_eulerian_hierholzer_circuit;
    validate_problem_size(1);
    std::vector<std::pair<int, int>> es = {{0, 1}, {1, 2}, {2, 0}, {0, 2}, {2, 1}, {1, 0}};
    auto tour = hierholzer_euler_circuit(3, es);
    assert(tour.size() == 7 && tour.front() == tour.back());
    verify_module_postcondition(true, "unit ok");
    return 0;
}
