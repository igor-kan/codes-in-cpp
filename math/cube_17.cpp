#include <cassert>
#include <iostream>

unsigned long long cube(int n){ return (unsigned long long)n*n*n; }

int main() {
    assert((cube(17)) == 4913);
    std::cout << "PASS cube_17\n";
    return 0;
}
