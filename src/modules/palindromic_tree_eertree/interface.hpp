#pragma once
#include "types.hpp"
#include "errors.hpp"

namespace codes_palindromic_tree_eertree {
class Eertree {
public:
    explicit Eertree(const std::string& s);
    int distinct_palindromes() const { return static_cast<int>(nodes_.size()) - 2; }
    int max_palindrome_length() const;
private:
    std::string s_;
    std::vector<EertreeNode> nodes_;
    int suff_ = 1;
    void add_char(int pos);
};

void validate_problem_size(int n);
std::int64_t fast_checksum_span(const std::vector<std::int64_t>& xs);
std::vector<std::int64_t> parallel_checksum_batches(const std::vector<std::vector<std::int64_t>>& batches);
void verify_module_postcondition(bool ok, const char* msg);
} // namespace codes_palindromic_tree_eertree
