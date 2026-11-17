#pragma once
#include "types.hpp"
#include "errors.hpp"

namespace codes_aho_corasick_flat_cpp {
class FlatAhoCorasick {
public:
    explicit FlatAhoCorasick(const std::vector<std::string>& patterns);
    int count_matches(const std::string& text) const;
    std::size_t state_count() const { return nodes_.size(); }
    const std::vector<FlatAcNode>& table() const { return nodes_; }

private:
    std::vector<FlatAcNode> nodes_;
};

void validate_patterns(const std::vector<std::string>& patterns);
int fast_count_char_stream(const FlatAhoCorasick& ac, const char* data, std::size_t len);
std::vector<int> parallel_scan_corpus(const std::vector<std::string>& patterns, const std::vector<std::string>& texts);
void verify_ac_parity(const std::vector<std::string>& patterns, const std::string& text, int got);
} // namespace codes_aho_corasick_flat_cpp
