#include "interface.hpp"
#include <algorithm>

namespace codes_bimap_bidirectional_index {
IntStrBiMap make_bimap() { return IntStrBiMap{}; }

Status insert_pair(IntStrBiMap& bm, int64_t key, const std::string& val) {
    if (val.empty()) return Status::InvalidInput;
    auto fit = std::lower_bound(bm.fwd_slots.begin(), bm.fwd_slots.end(), key,
        [](const BiMapSlot& s, int64_t k) { return s.key < k; });
    auto rit = std::lower_bound(bm.rev_pairs.begin(), bm.rev_pairs.end(), val,
        [](const auto& p, const std::string& v) { return p.first < v; });
    bool has_k = (fit != bm.fwd_slots.end() && fit->key == key);
    bool has_v = (rit != bm.rev_pairs.end() && rit->first == val);
    if (has_k && has_v && fit->val == val && rit->second == key) return Status::Ok;
    if (has_k || has_v) {
        ++bm.conflicts;
        return Status::InvariantViolation;
    }
    std::size_t fpos = static_cast<std::size_t>(fit - bm.fwd_slots.begin());
    bm.fwd_slots.insert(bm.fwd_slots.begin() + static_cast<std::ptrdiff_t>(fpos), BiMapSlot{key, val, true});
    try {
        rit = std::lower_bound(bm.rev_pairs.begin(), bm.rev_pairs.end(), val,
            [](const auto& p, const std::string& v) { return p.first < v; });
        bm.rev_pairs.insert(rit, {val, key});
    } catch (...) {
        bm.fwd_slots.erase(bm.fwd_slots.begin() + static_cast<std::ptrdiff_t>(fpos));
        throw;
    }
    ++bm.count;
    return Status::Ok;
}

bool find_by_key(const IntStrBiMap& bm, int64_t key, std::string& out) {
    auto it = std::lower_bound(bm.fwd_slots.begin(), bm.fwd_slots.end(), key,
        [](const BiMapSlot& s, int64_t k) { return s.key < k; });
    if (it == bm.fwd_slots.end() || it->key != key) return false;
    out = it->val;
    return true;
}

bool find_by_val(const IntStrBiMap& bm, const std::string& val, int64_t& out) {
    auto it = std::lower_bound(bm.rev_pairs.begin(), bm.rev_pairs.end(), val,
        [](const auto& p, const std::string& v) { return p.first < v; });
    if (it == bm.rev_pairs.end() || it->first != val) return false;
    out = it->second;
    return true;
}

bool erase_by_key(IntStrBiMap& bm, int64_t key) {
    auto fit = std::lower_bound(bm.fwd_slots.begin(), bm.fwd_slots.end(), key,
        [](const BiMapSlot& s, int64_t k) { return s.key < k; });
    if (fit == bm.fwd_slots.end() || fit->key != key) return false;
    std::string val = fit->val;
    bm.fwd_slots.erase(fit);
    auto rit = std::lower_bound(bm.rev_pairs.begin(), bm.rev_pairs.end(), val,
        [](const auto& p, const std::string& v) { return p.first < v; });
    if (rit != bm.rev_pairs.end() && rit->first == val) bm.rev_pairs.erase(rit);
    --bm.count;
    return true;
}

std::size_t bimap_size(const IntStrBiMap& bm) { return bm.count; }
std::size_t bimap_conflicts(const IntStrBiMap& bm) { return bm.conflicts; }
} // namespace codes_bimap_bidirectional_index
