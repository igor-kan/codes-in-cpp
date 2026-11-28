#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_leftist_heap_d61;
    auto chks = parallel_checksum_batches({{1, 2, 3}, {4, 5, 6}});
    assert(chks.size() == 2 && chks[0] != chks[1]);
    LeftistHeap heap;
    int root = -1;
    std::int64_t expect = 0;
    for (int i = 0; i < 40; ++i) {
        std::int64_t key = (i * 53) % 97;
        root = heap.meld(root, heap.make(key));
        expect += key;
    }
    assert(heap.total(root) == expect);
    std::int64_t prev = -1;
    int produced = 0;
    while (root >= 0) {
        std::int64_t cur = heap.peek_min(root);
        assert(cur >= prev);
        prev = cur;
        root = heap.pop_min(root);
        ++produced;
    }
    assert(produced == 40);
    return 0;
}
