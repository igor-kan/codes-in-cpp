#pragma once
#include "types.hpp"
#include "errors.hpp"

namespace codes_bk_tree_metric_d61 {
class BkTree {
public:
    void insert(const std::string& word);
    std::vector<std::string> search(const std::string& query, int max_dist) const;
    int size() const;
private:
    struct Node {
        std::string word;
        std::vector<int> kids;
        std::vector<int> dists;
    };
    std::vector<Node> nodes_;
    int root_ = -1;
    static int edit_distance(const std::string& a, const std::string& b);
};

void validate_problem_size(int n);
std::int64_t fast_checksum_span(const std::vector<std::int64_t>& xs);
std::vector<std::int64_t> parallel_checksum_batches(const std::vector<std::vector<std::int64_t>>& batches);
void verify_module_postcondition(bool ok, const char* msg);
} // namespace codes_bk_tree_metric_d61
