#pragma once
#include "types.hpp"
#include "errors.hpp"

namespace codes_bimap_bidirectional_index {
IntStrBiMap make_bimap();
Status insert_pair(IntStrBiMap& bm, int64_t key, const std::string& val);
bool find_by_key(const IntStrBiMap& bm, int64_t key, std::string& out);
bool find_by_val(const IntStrBiMap& bm, const std::string& val, int64_t& out);
bool erase_by_key(IntStrBiMap& bm, int64_t key);
std::size_t bimap_size(const IntStrBiMap& bm);
std::size_t bimap_conflicts(const IntStrBiMap& bm);
std::vector<bool> batch_verify_keys(const IntStrBiMap& bm, const std::vector<int64_t>& keys);
Status verify_bimap_invariants(const IntStrBiMap& bm);
} // namespace codes_bimap_bidirectional_index
