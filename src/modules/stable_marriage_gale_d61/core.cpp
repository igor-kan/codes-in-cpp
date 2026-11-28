#include "interface.hpp"
#include <algorithm>
#include <cmath>
#include <limits>
#include <numeric>
#include <queue>

namespace codes_stable_marriage_gale_d61 {

StableMarriage::StableMarriage(int n) : n_(n > 0 ? n : 0) {
    std::size_t dim = static_cast<std::size_t>(n_);
    proposer_pref_.assign(dim, std::vector<int>());
    receiver_rank_.assign(dim, std::vector<int>(dim, n_));
}
int StableMarriage::size() const {
    return n_;
}
void StableMarriage::set_proposer_preferences(int proposer, const std::vector<int>& order) {
    if (proposer < 0 || proposer >= n_) return;
    std::vector<int> cleaned;
    for (int receiver : order) {
        if (receiver < 0 || receiver >= n_) continue;
        if (std::find(cleaned.begin(), cleaned.end(), receiver) == cleaned.end()) {
            cleaned.push_back(receiver);
        }
    }
    proposer_pref_[static_cast<std::size_t>(proposer)] = cleaned;
}
void StableMarriage::set_receiver_preferences(int receiver, const std::vector<int>& order) {
    if (receiver < 0 || receiver >= n_) return;
    std::vector<int> rank(static_cast<std::size_t>(n_), n_);
    int position = 0;
    for (int proposer : order) {
        if (proposer < 0 || proposer >= n_) continue;
        if (rank[static_cast<std::size_t>(proposer)] == n_) {
            rank[static_cast<std::size_t>(proposer)] = position;
            ++position;
        }
    }
    receiver_rank_[static_cast<std::size_t>(receiver)] = rank;
}
std::vector<int> StableMarriage::solve() const {
    std::vector<int> match(static_cast<std::size_t>(n_), -1);
    if (n_ <= 0) return match;
    std::vector<int> held(static_cast<std::size_t>(n_), -1);
    std::vector<int> next_choice(static_cast<std::size_t>(n_), 0);
    std::vector<int> free_stack;
    free_stack.reserve(static_cast<std::size_t>(n_));
    for (int proposer = 0; proposer < n_; ++proposer) free_stack.push_back(proposer);
    while (!free_stack.empty()) {
        int proposer = free_stack.back();
        free_stack.pop_back();
        if (match[static_cast<std::size_t>(proposer)] >= 0) continue;
        const std::vector<int>& prefs = proposer_pref_[static_cast<std::size_t>(proposer)];
        while (next_choice[static_cast<std::size_t>(proposer)] < static_cast<int>(prefs.size())) {
            int receiver = prefs[static_cast<std::size_t>(next_choice[static_cast<std::size_t>(proposer)]++)];
            if (receiver < 0 || receiver >= n_) continue;
            int current = held[static_cast<std::size_t>(receiver)];
            if (current < 0) {
                match[static_cast<std::size_t>(proposer)] = receiver;
                held[static_cast<std::size_t>(receiver)] = proposer;
                break;
            }
            if (receiver_rank_[static_cast<std::size_t>(receiver)][static_cast<std::size_t>(proposer)] <
                receiver_rank_[static_cast<std::size_t>(receiver)][static_cast<std::size_t>(current)]) {
                match[static_cast<std::size_t>(current)] = -1;
                free_stack.push_back(current);
                match[static_cast<std::size_t>(proposer)] = receiver;
                held[static_cast<std::size_t>(receiver)] = proposer;
                break;
            }
        }
    }
    return match;
}
bool StableMarriage::is_stable(const std::vector<int>& match) const {
    if (static_cast<int>(match.size()) != n_) return false;
    std::vector<int> held(static_cast<std::size_t>(n_), -1);
    for (int proposer = 0; proposer < n_; ++proposer) {
        int receiver = match[static_cast<std::size_t>(proposer)];
        if (receiver < 0 || receiver >= n_) return false;
        if (held[static_cast<std::size_t>(receiver)] >= 0) return false;
        held[static_cast<std::size_t>(receiver)] = proposer;
    }
    for (int proposer = 0; proposer < n_; ++proposer) {
        int partner = match[static_cast<std::size_t>(proposer)];
        const std::vector<int>& prefs = proposer_pref_[static_cast<std::size_t>(proposer)];
        for (int candidate : prefs) {
            if (candidate == partner) break;
            if (candidate < 0 || candidate >= n_) continue;
            int current = held[static_cast<std::size_t>(candidate)];
            if (current < 0) continue;
            if (receiver_rank_[static_cast<std::size_t>(candidate)][static_cast<std::size_t>(proposer)] <
                receiver_rank_[static_cast<std::size_t>(candidate)][static_cast<std::size_t>(current)]) {
                return false;
            }
        }
    }
    return true;
}
std::vector<MatchPair> StableMarriage::pairs(const std::vector<int>& match) const {
    std::vector<MatchPair> out;
    if (static_cast<int>(match.size()) != n_) return out;
    out.reserve(static_cast<std::size_t>(n_));
    for (int proposer = 0; proposer < n_; ++proposer) {
        int receiver = match[static_cast<std::size_t>(proposer)];
        if (receiver >= 0 && receiver < n_) {
            out.push_back(MatchPair{proposer, receiver});
        }
    }
    return out;
}

} // namespace codes_stable_marriage_gale_d61
