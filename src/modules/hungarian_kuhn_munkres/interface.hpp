#pragma once
#include "types.hpp"
#include "errors.hpp"

namespace codes_hungarian_kuhn_munkres {
AssignmentResult solve_hungarian(std::size_t rows, std::size_t cols, const std::vector<long long>& cost_matrix);
Status validate_cost_matrix(std::size_t rows, std::size_t cols, const std::vector<long long>& mat);
long long evaluate_assignment_cost(std::size_t cols, const std::vector<long long>& mat, const std::vector<std::size_t>& assign);
std::vector<AssignmentResult> parallel_solve_assignments(std::size_t n, const std::vector<std::vector<long long>>& matrices);
Status verify_assignment_bijection(std::size_t rows, std::size_t cols, const std::vector<long long>& mat, const AssignmentResult& res);
} // namespace codes_hungarian_kuhn_munkres
