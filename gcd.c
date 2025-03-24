#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>


int gcd(int a, int b) {
    int r = a % b;

    if (r == 0)
        return b;
    return gcd(b, r);
}



int main() {
    
    printf("%d\n", gcd(54, 12));

    return 0;
}