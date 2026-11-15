#include "interface.hpp"

namespace codes_nelder_mead_simplex {
Status validate_nm_config(const std::vector<double>& x0, const NelderMeadConfig& cfg) {
    if (x0.empty()) return Status::NullOrEmpty;
    if (cfg.alpha <= 0.0 || cfg.gamma <= 1.0 || cfg.rho <= 0.0 || cfg.rho >= 1.0) return Status::InvalidInput;
    return Status::Ok;
}
} // namespace codes_nelder_mead_simplex
