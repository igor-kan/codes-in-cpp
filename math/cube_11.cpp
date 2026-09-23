#include <cassert>
#include <iostream>

unsigned long long cube(int n){ return (unsigned long long)n*n*n; }

int main() {
    assert((cube(11)) == 1331);
    std::cout << "PASS cube_11\n";
    return 0;
}
