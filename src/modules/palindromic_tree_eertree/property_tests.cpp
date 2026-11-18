#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_palindromic_tree_eertree;
    auto chks = parallel_checksum_batches({{1, 2, 3}, {4, 5, 6}});
    assert(chks.size() == 2 && chks[0] != chks[1]);
    Eertree et("aaaaa");
    assert(et.distinct_palindromes() == 5 && et.max_palindrome_length() == 5);
    return 0;
}
