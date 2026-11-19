#include "interface.hpp"
#include <algorithm>
#include <cmath>
#include <limits>
#include <numeric>
#include <queue>

namespace codes_convex_hull_trick_deque {

bool MonotoneCht::bad(ChtLine l1, ChtLine l2, ChtLine l3) {
    return static_cast<__int128>(l3.b - l1.b) * (l1.m - l2.m) <= static_cast<__int128>(l2.b - l1.b) * (l1.m - l3.m);
}
void MonotoneCht::add_line(std::int64_t m, std::int64_t b) {
    ChtLine nw{m, b};
    while (hull_.size() >= head_ + 2 && bad(hull_[hull_.size() - 2], hull_.back(), nw)) hull_.pop_back();
    hull_.push_back(nw);
}
std::int64_t MonotoneCht::query(std::int64_t x) {
    while (head_ + 1 < hull_.size() && hull_[head_ + 1].eval(x) <= hull_[head_].eval(x)) ++head_;
    return hull_[head_].eval(x);
}

} // namespace codes_convex_hull_trick_deque
