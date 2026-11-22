#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_suffix_array_doubling_d57;
    auto chks = parallel_checksum_batches({{1, 2, 3}, {4, 5, 6}});
    assert(chks.size() == 2 && chks[0] != chks[1]);
    std::string t = "mississippi";
    auto sa = build_suffix_array(t);
    for (std::size_t i = 1; i < sa.size(); ++i) assert(t.substr(sa[i - 1]) < t.substr(sa[i]));
    return 0;
}
