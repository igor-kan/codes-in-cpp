#include <cassert>
#include <iostream>

unsigned long long cube(int n){ return (unsigned long long)n*n*n; }

int main() {
    assert((cube(14)) == 2744);
    std::cout << "PASS cube_14\n";
    return 0;
}
