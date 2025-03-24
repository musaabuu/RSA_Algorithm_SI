#include <iostream>
#include <stacktrace>

int gcd(int a, int b) {
    
    std::cout << std::stacktrace::current() << '\n';

    int r = a % b;

    if (r == 0)
        return b;
    return gcd(b, r);
}



int main() {
    
    std::cout << gcd(54, 12);

    return 0;
}