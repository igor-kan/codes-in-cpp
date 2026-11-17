#include "interface.hpp"
#include <queue>

namespace codes_aho_corasick_flat_cpp {

FlatAhoCorasick::FlatAhoCorasick(const std::vector<std::string>& patterns) {
    validate_patterns(patterns);
    nodes_.push_back(FlatAcNode{});
    for (const auto& pat : patterns) {
        int cur = 0;
        for (char ch : pat) {
            int c = ch - 'a';
            if (nodes_[static_cast<std::size_t>(cur)].next[static_cast<std::size_t>(c)] == 0) {
                nodes_[static_cast<std::size_t>(cur)].next[static_cast<std::size_t>(c)] = static_cast<int>(nodes_.size());
                nodes_.push_back(FlatAcNode{});
            }
            cur = nodes_[static_cast<std::size_t>(cur)].next[static_cast<std::size_t>(c)];
        }
        nodes_[static_cast<std::size_t>(cur)].out_count += 1;
    }
    std::queue<int> q;
    for (int c = 0; c < 26; ++c) {
        int nxt = nodes_[0].next[static_cast<std::size_t>(c)];
        if (nxt != 0) q.push(nxt);
    }
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        int f = nodes_[static_cast<std::size_t>(v)].fail;
        nodes_[static_cast<std::size_t>(v)].out_count += nodes_[static_cast<std::size_t>(f)].out_count;
        for (int c = 0; c < 26; ++c) {
            int& ch_id = nodes_[static_cast<std::size_t>(v)].next[static_cast<std::size_t>(c)];
            if (ch_id != 0) {
                nodes_[static_cast<std::size_t>(ch_id)].fail = nodes_[static_cast<std::size_t>(f)].next[static_cast<std::size_t>(c)];
                q.push(ch_id);
            } else {
                ch_id = nodes_[static_cast<std::size_t>(f)].next[static_cast<std::size_t>(c)];
            }
        }
    }
}

int FlatAhoCorasick::count_matches(const std::string& text) const {
    return fast_count_char_stream(*this, text.data(), text.size());
}

} // namespace codes_aho_corasick_flat_cpp
