#include "interface.hpp"
#include <algorithm>

namespace codes_skiplist_index_cpp {

SkipListIndex::SkipListIndex() {
    SkipNode head;
    head.next.fill(-1);
    head.height = SL_MAX_LEVEL;
    nodes_.push_back(head);
}

int SkipListIndex::random_height() {
    rng_ ^= rng_ >> 12;
    rng_ ^= rng_ << 25;
    rng_ ^= rng_ >> 27;
    std::uint64_t z = rng_ * 0x2545F4914F6CDD1DULL;
    int h = 1;
    while (h < SL_MAX_LEVEL && (z & 3ULL) == 0ULL) {
        ++h;
        z >>= 2;
    }
    return h;
}

bool SkipListIndex::upsert(std::int64_t key, std::int64_t val) {
    std::array<int, SL_MAX_LEVEL> update{};
    update.fill(0);
    int cur = 0;
    for (int lvl = max_level_ - 1; lvl >= 0; --lvl) {
        while (nodes_[static_cast<std::size_t>(cur)].next[static_cast<std::size_t>(lvl)] != -1 &&
               nodes_[static_cast<std::size_t>(nodes_[static_cast<std::size_t>(cur)].next[static_cast<std::size_t>(lvl)])].key < key) {
            cur = nodes_[static_cast<std::size_t>(cur)].next[static_cast<std::size_t>(lvl)];
        }
        update[static_cast<std::size_t>(lvl)] = cur;
    }
    int nxt = nodes_[static_cast<std::size_t>(cur)].next[0];
    if (nxt != -1 && nodes_[static_cast<std::size_t>(nxt)].key == key) {
        nodes_[static_cast<std::size_t>(nxt)].val = val;
        return false;
    }
    int h = random_height();
    max_level_ = std::max(max_level_, h);
    int id = static_cast<int>(nodes_.size());
    SkipNode nn;
    nn.key = key;
    nn.val = val;
    nn.height = h;
    nn.next.fill(-1);
    for (int lvl = 0; lvl < h; ++lvl) {
        nn.next[static_cast<std::size_t>(lvl)] = nodes_[static_cast<std::size_t>(update[static_cast<std::size_t>(lvl)])].next[static_cast<std::size_t>(lvl)];
        nodes_[static_cast<std::size_t>(update[static_cast<std::size_t>(lvl)])].next[static_cast<std::size_t>(lvl)] = id;
    }
    nodes_.push_back(nn);
    ++count_;
    return true;
}

bool SkipListIndex::find(std::int64_t key, std::int64_t& out) const {
    int cur = 0;
    for (int lvl = max_level_ - 1; lvl >= 0; --lvl) {
        while (nodes_[static_cast<std::size_t>(cur)].next[static_cast<std::size_t>(lvl)] != -1 &&
               nodes_[static_cast<std::size_t>(nodes_[static_cast<std::size_t>(cur)].next[static_cast<std::size_t>(lvl)])].key < key) {
            cur = nodes_[static_cast<std::size_t>(cur)].next[static_cast<std::size_t>(lvl)];
        }
    }
    int nxt = nodes_[static_cast<std::size_t>(cur)].next[0];
    if (nxt != -1 && nodes_[static_cast<std::size_t>(nxt)].key == key) {
        out = nodes_[static_cast<std::size_t>(nxt)].val;
        return true;
    }
    return false;
}

std::vector<std::int64_t> SkipListIndex::range_values(std::int64_t lo, std::int64_t hi) const {
    validate_range_bounds(lo, hi);
    int cur = 0;
    for (int lvl = max_level_ - 1; lvl >= 0; --lvl) {
        while (nodes_[static_cast<std::size_t>(cur)].next[static_cast<std::size_t>(lvl)] != -1 &&
               nodes_[static_cast<std::size_t>(nodes_[static_cast<std::size_t>(cur)].next[static_cast<std::size_t>(lvl)])].key < lo) {
            cur = nodes_[static_cast<std::size_t>(cur)].next[static_cast<std::size_t>(lvl)];
        }
    }
    int nxt = nodes_[static_cast<std::size_t>(cur)].next[0];
    std::vector<std::int64_t> res;
    while (nxt != -1 && nodes_[static_cast<std::size_t>(nxt)].key <= hi) {
        res.push_back(nodes_[static_cast<std::size_t>(nxt)].val);
        nxt = nodes_[static_cast<std::size_t>(nxt)].next[0];
    }
    return res;
}

} // namespace codes_skiplist_index_cpp
