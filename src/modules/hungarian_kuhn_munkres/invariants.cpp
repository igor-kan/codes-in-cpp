#include "interface.hpp"

namespace codes_hungarian_kuhn_munkres {
Status verify_assignment_bijection(std::size_t rows, std::size_t cols, const std::vector<long long>& mat, const AssignmentResult& res) {
    if (res.col_for_row.size() != rows) return Status::InvariantViolation;
    std::vector<bool> seen(cols, false);
    for (std::size_t c : res.col_for_row) {
        if (c >= cols || seen[c]) return Status::InvariantViolation;
        seen[c] = true;
    }
    if (evaluate_assignment_cost(cols, mat, res.col_for_row) != res.min_cost) return Status::InvariantViolation;
    return Status::Ok;
}
} // namespace codes_hungarian_kuhn_munkres
