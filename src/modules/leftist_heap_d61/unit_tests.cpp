#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_leftist_heap_d61;
    validate_problem_size(1);
    LeftistHeap heap;
    int root = heap.make(7);
    root = heap.meld(root, heap.make(2));
    root = heap.meld(root, heap.make(11));
    root = heap.meld(root, heap.make(4));
    assert(heap.peek_min(root) == 2);
    assert(heap.total(root) == 24);
    root = heap.pop_min(root);
    assert(heap.peek_min(root) == 4);
    verify_module_postcondition(true, "unit ok");
    return 0;
}
