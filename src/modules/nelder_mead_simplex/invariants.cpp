#include "interface.hpp"

namespace codes_nelder_mead_simplex {
Status verify_descent_from_start(const std::function<double(const std::vector<double>&)>& fn, const std::vector<double>& x0, const NelderMeadResult& res) {
    if (res.best_x.size() != x0.size()) return Status::InvariantViolation;
    if (res.best_f > fn(x0) + 1e-12) return Status::InvariantViolation;
    return Status::Ok;
}
} // namespace codes_nelder_mead_simplex
