#include <cassert>
#include <iostream>

unsigned long long fib(int n){ unsigned long long a=0,b=1,t; for(int i=0;i<n;i++){t=a+b;a=b;b=t;} return a; }

int main() {
    assert((fib(69)) == 117669030460994);
    std::cout << "PASS fib_69\n";
    return 0;
}
