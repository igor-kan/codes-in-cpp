#include "interface.hpp"
#include <chrono>
#include <iostream>

int main() {
    using namespace codes_leftist_heap_d61;
    LeftistHeap heap;
    int root = -1;
    auto t0 = std::chrono::steady_clock::now();
    volatile std::int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        root = heap.meld(root, heap.make((iter * 11) % 53));
    sink = sink + heap.peek_min(root);
    }
    auto t1 = std::chrono::steady_clock::now();
    auto us = std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count();
    std::cout << "leftist_heap_d61 us=" << us << " sink=" << sink << "\n";
    return 0;
}
