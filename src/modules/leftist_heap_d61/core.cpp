#include "interface.hpp"
#include <algorithm>
#include <cmath>
#include <limits>
#include <numeric>
#include <queue>

namespace codes_leftist_heap_d61 {

int LeftistHeap::make(std::int64_t key) {
    int id = static_cast<int>(nodes_.size());
    nodes_.push_back(LeftistNode{key, -1, -1, 1});
    return id;
}
int LeftistHeap::meld(int a, int b) {
    if (a < 0) return b;
    if (b < 0) return a;
    if (nodes_[a].key > nodes_[b].key) std::swap(a, b);
    nodes_[a].right = meld(nodes_[a].right, b);
    int lr = nodes_[a].left < 0 ? 0 : nodes_[nodes_[a].left].rank;
    int rr = nodes_[a].right < 0 ? 0 : nodes_[nodes_[a].right].rank;
    if (lr < rr) std::swap(nodes_[a].left, nodes_[a].right);
    int new_rr = nodes_[a].right < 0 ? 0 : nodes_[nodes_[a].right].rank;
    nodes_[a].rank = new_rr + 1;
    return a;
}
std::int64_t LeftistHeap::peek_min(int root) const {
    return root < 0 ? 0 : nodes_[root].key;
}
int LeftistHeap::pop_min(int root) {
    if (root < 0) return -1;
    return meld(nodes_[root].left, nodes_[root].right);
}
std::int64_t LeftistHeap::total(int root) const {
    if (root < 0) return 0;
    std::int64_t acc = 0;
    std::vector<int> stack;
    stack.push_back(root);
    while (!stack.empty()) {
        int u = stack.back();
        stack.pop_back();
        acc += nodes_[u].key;
        if (nodes_[u].left >= 0) stack.push_back(nodes_[u].left);
        if (nodes_[u].right >= 0) stack.push_back(nodes_[u].right);
    }
    return acc;
}

} // namespace codes_leftist_heap_d61
