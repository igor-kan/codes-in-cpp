#include "interface.hpp"
#include <algorithm>
#include <cmath>
#include <limits>
#include <numeric>
#include <queue>

namespace codes_bk_tree_metric_d61 {

int BkTree::edit_distance(const std::string& a, const std::string& b) {
    std::size_t n = a.size(), m = b.size();
    std::vector<int> prev(m + 1, 0), cur(m + 1, 0);
    for (std::size_t j = 0; j <= m; ++j) prev[j] = static_cast<int>(j);
    for (std::size_t i = 1; i <= n; ++i) {
        cur[0] = static_cast<int>(i);
        for (std::size_t j = 1; j <= m; ++j) {
            int sub = prev[j - 1] + (a[i - 1] == b[j - 1] ? 0 : 1);
            int del = prev[j] + 1;
            int ins = cur[j - 1] + 1;
            int best = sub < del ? sub : del;
            cur[j] = best < ins ? best : ins;
        }
        prev.swap(cur);
    }
    return prev[m];
}
void BkTree::insert(const std::string& word) {
    if (root_ < 0) {
        root_ = 0;
        nodes_.push_back(Node{word, {}, {}});
        return;
    }
    int cur = root_;
    for (;;) {
        int d = edit_distance(word, nodes_[static_cast<std::size_t>(cur)].word);
        if (d == 0) return;
        int nxt = -1;
        for (std::size_t i = 0; i < nodes_[static_cast<std::size_t>(cur)].kids.size(); ++i) {
            if (nodes_[static_cast<std::size_t>(cur)].dists[i] == d) {
                nxt = nodes_[static_cast<std::size_t>(cur)].kids[i];
                break;
            }
        }
        if (nxt < 0) {
            int id = static_cast<int>(nodes_.size());
            nodes_.push_back(Node{word, {}, {}});
            nodes_[static_cast<std::size_t>(cur)].kids.push_back(id);
            nodes_[static_cast<std::size_t>(cur)].dists.push_back(d);
            return;
        }
        cur = nxt;
    }
}
std::vector<std::string> BkTree::search(const std::string& query, int max_dist) const {
    std::vector<std::string> out;
    if (root_ < 0) return out;
    std::vector<int> stack;
    stack.push_back(root_);
    while (!stack.empty()) {
        int cur = stack.back();
        stack.pop_back();
        int d = edit_distance(query, nodes_[static_cast<std::size_t>(cur)].word);
        if (d <= max_dist) out.push_back(nodes_[static_cast<std::size_t>(cur)].word);
        for (std::size_t i = 0; i < nodes_[static_cast<std::size_t>(cur)].kids.size(); ++i) {
            int gap = d - nodes_[static_cast<std::size_t>(cur)].dists[i];
            if (gap < 0) gap = -gap;
            if (gap <= max_dist) stack.push_back(nodes_[static_cast<std::size_t>(cur)].kids[i]);
        }
    }
    return out;
}
int BkTree::size() const {
    return static_cast<int>(nodes_.size());
}

} // namespace codes_bk_tree_metric_d61
