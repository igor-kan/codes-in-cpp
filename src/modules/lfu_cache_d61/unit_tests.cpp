#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_lfu_cache_d61;
    validate_problem_size(1);
    LfuCache cache(2);
    cache.put(1, 10);
    cache.put(2, 20);
    std::int64_t value = 0;
    assert(cache.get(1, value) && value == 10);
    cache.put(3, 30);
    std::int64_t miss = 0;
    assert(!cache.get(2, miss));
    assert(cache.get(1, value) && value == 10);
    assert(cache.get(3, value) && value == 30);
    assert(cache.size() == 2);
    verify_module_postcondition(true, "unit ok");
    return 0;
}
