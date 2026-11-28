#include "interface.hpp"
#include <algorithm>
#include <cmath>
#include <limits>
#include <numeric>
#include <queue>

namespace codes_chtholly_tree_d61 {

ChthollyTree::ChthollyTree(int size) {
    if (size > 0) segs_.push_back(IntervalNode{0, size - 1, 0});
}
void ChthollyTree::assign(int l, int r, std::int64_t val) {
    if (l > r) return;
    std::vector<IntervalNode> next;
    next.reserve(segs_.size() + 2);
    for (std::size_t i = 0; i < segs_.size(); ++i) {
        const IntervalNode& seg = segs_[i];
        if (seg.r < l || seg.l > r) {
            next.push_back(seg);
            continue;
        }
        if (seg.l < l) next.push_back(IntervalNode{seg.l, l - 1, seg.val});
        if (seg.r > r) next.push_back(IntervalNode{r + 1, seg.r, seg.val});
    }
    next.push_back(IntervalNode{l, r, val});
    std::sort(next.begin(), next.end(), [](const IntervalNode& a, const IntervalNode& b) {
        return a.l < b.l;
    });
    segs_.swap(next);
}
std::int64_t ChthollyTree::range_sum(int l, int r) const {
    std::int64_t acc = 0;
    for (std::size_t i = 0; i < segs_.size(); ++i) {
        const IntervalNode& seg = segs_[i];
        if (seg.r < l || seg.l > r) continue;
        int lo = seg.l > l ? seg.l : l;
        int hi = seg.r < r ? seg.r : r;
        acc += seg.val * (hi - lo + 1);
    }
    return acc;
}
std::size_t ChthollyTree::interval_count() const {
    return segs_.size();
}

} // namespace codes_chtholly_tree_d61
