#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_eulerian_hierholzer_circuit;
    auto chks = parallel_checksum_batches({{1, 2, 3}, {4, 5, 6}});
    assert(chks.size() == 2 && chks[0] != chks[1]);
    std::vector<std::pair<int, int>> cycle = {{0, 1}, {1, 2}, {2, 3}, {3, 0}};
    auto tour = hierholzer_euler_circuit(4, cycle);
    assert(tour.size() == 5 && tour.front() == 0 && tour.back() == 0);
    return 0;
}
