#pragma once
#include "types.hpp"
#include "errors.hpp"

namespace codes_stable_marriage_gale_d61 {
class StableMarriage {
public:
    explicit StableMarriage(int n);
    void set_proposer_preferences(int proposer, const std::vector<int>& order);
    void set_receiver_preferences(int receiver, const std::vector<int>& order);
    std::vector<int> solve() const;
    bool is_stable(const std::vector<int>& match) const;
    std::vector<MatchPair> pairs(const std::vector<int>& match) const;
    int size() const;
private:
    int n_ = 0;
    std::vector<std::vector<int>> proposer_pref_;
    std::vector<std::vector<int>> receiver_rank_;
};

void validate_problem_size(int n);
std::int64_t fast_checksum_span(const std::vector<std::int64_t>& xs);
std::vector<std::int64_t> parallel_checksum_batches(const std::vector<std::vector<std::int64_t>>& batches);
void verify_module_postcondition(bool ok, const char* msg);
} // namespace codes_stable_marriage_gale_d61
