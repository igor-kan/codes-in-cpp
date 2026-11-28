#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_bk_tree_metric_d61;
    validate_problem_size(1);
    BkTree bk;
    bk.insert("cat");
    bk.insert("cot");
    bk.insert("cut");
    bk.insert("dog");
    bk.insert("cats");
    auto hits = bk.search("cut", 1);
    assert(hits.size() == 3);
    bool saw_cat = false, saw_cut = false, saw_dog = false;
    for (std::size_t i = 0; i < hits.size(); ++i) {
        if (hits[i] == "cat") saw_cat = true;
        if (hits[i] == "cut") saw_cut = true;
        if (hits[i] == "dog") saw_dog = true;
    }
    assert(saw_cat && saw_cut && !saw_dog);
    verify_module_postcondition(true, "unit ok");
    return 0;
}
