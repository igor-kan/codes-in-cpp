#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_manacher_pal_d60;
    auto chks = parallel_checksum_batches({{1, 2, 3}, {4, 5, 6}});
    assert(chks.size() == 2 && chks[0] != chks[1]);
    std::string s = "abacdfgdcabaabac";
    auto p = longest_palindrome_d60(s);
    assert(p.length >= 4);
    for (int i = 0; i < p.length; ++i) {
        assert(s[p.start + i] == s[p.start + p.length - 1 - i]);
    }
    return 0;
}
