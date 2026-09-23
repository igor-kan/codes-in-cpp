#include <cassert>
#include <iostream>

unsigned long long cube(int n){ return (unsigned long long)n*n*n; }

int main() {
    assert((cube(10)) == 1000);
    std::cout << "PASS cube_10\n";
    return 0;
}
