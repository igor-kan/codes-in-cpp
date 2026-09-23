#include <cassert>
#include <iostream>

unsigned long long cube(int n){ return (unsigned long long)n*n*n; }

int main() {
    assert((cube(20)) == 8000);
    std::cout << "PASS cube_20\n";
    return 0;
}
