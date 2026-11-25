#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_z_algorithm_lcp_d60;
    auto chks = parallel_checksum_batches({{1, 2, 3}, {4, 5, 6}});
    assert(chks.size() == 2 && chks[0] != chks[1]);
    std::string s = "aabxaabxcaabxaabxay";
    auto z = compute_z_array(s);
    for (int i = 1; i < static_cast<int>(s.size()); ++i) {
        int exact = 0;
        while (i + exact < static_cast<int>(s.size()) && s[exact] == s[i + exact]) ++exact;
        assert(z[i] == exact);
    }
    return 0;
}
