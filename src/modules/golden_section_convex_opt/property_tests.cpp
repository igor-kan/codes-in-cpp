#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_golden_section_convex_opt;
    auto chks = parallel_checksum_batches({{1, 2, 3}, {4, 5, 6}});
    assert(chks.size() == 2 && chks[0] != chks[1]);
    auto fn = +[](double x) { return x * x + 4.0 * x + 7.0; };
    auto res = golden_section_minimize(fn, -10.0, 5.0, 1e-8);
    assert(std::fabs(res.x + 2.0) < 1e-6);
    return 0;
}
