#include "interface.hpp"
#include <cassert>

int main() {
    using namespace codes_aho_corasick_flat_cpp;
    auto counts = parallel_scan_corpus({"ab", "aba", "ba"}, {"ababa", "baba", "xyz"});
    assert((counts == std::vector<int>{6, 4, 0}));
    return 0;
}
