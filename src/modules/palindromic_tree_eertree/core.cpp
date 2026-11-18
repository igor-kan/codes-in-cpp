#include "interface.hpp"
#include <algorithm>
#include <cmath>
#include <limits>
#include <numeric>
#include <queue>

namespace codes_palindromic_tree_eertree {

Eertree::Eertree(const std::string& s) : s_(s) {
    nodes_.emplace_back(-1, 0);
    nodes_.emplace_back(0, 0);
    for (int i = 0; i < static_cast<int>(s_.size()); ++i) add_char(i);
}

void Eertree::add_char(int pos) {
    int cur = suff_, c = s_[pos] - 'a';
    while (true) {
        int curlen = nodes_[cur].len;
        if (pos - 1 - curlen >= 0 && s_[pos - 1 - curlen] == s_[pos]) break;
        cur = nodes_[cur].link;
    }
    if (nodes_[cur].next[c] != -1) {
        suff_ = nodes_[cur].next[c];
        return;
    }
    int nw = static_cast<int>(nodes_.size());
    nodes_.emplace_back(nodes_[cur].len + 2, 1);
    nodes_[cur].next[c] = nw;
    suff_ = nw;
    if (nodes_[nw].len == 1) return;
    while (true) {
        cur = nodes_[cur].link;
        int curlen = nodes_[cur].len;
        if (pos - 1 - curlen >= 0 && s_[pos - 1 - curlen] == s_[pos]) {
            nodes_[nw].link = nodes_[cur].next[c];
            break;
        }
    }
}

int Eertree::max_palindrome_length() const {
    int mx = 0;
    for (const auto& nd : nodes_) if (nd.len > mx) mx = nd.len;
    return mx;
}

} // namespace codes_palindromic_tree_eertree
