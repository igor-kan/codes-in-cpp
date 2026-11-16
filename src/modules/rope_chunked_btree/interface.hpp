#pragma once
#include "types.hpp"
#include "errors.hpp"

namespace codes_rope_chunked_btree {
RopeStore rope_from_string(const std::string& s);
char rope_at(const RopeStore& r, std::size_t idx);
Status validate_rope_range(const RopeStore& r, std::size_t start, std::size_t len);
void rope_append(RopeStore& r, const std::string& suffix);
void rope_insert(RopeStore& r, std::size_t pos, const std::string& ins);
std::string rope_flatten(const RopeStore& r);
std::vector<std::string> batch_flatten(const std::vector<RopeStore>& ropes);
Status verify_rope_invariants(const RopeStore& r, const std::string& expected);
} // namespace codes_rope_chunked_btree
