#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

// typedef struct {
//     int a, b, r;
// } Register;


// typedef struct {
//     Register* value;
//     int sommet;
// } Pile;

// Pile pileGlobal;

// void init_pile(Pile* pile){
//     pile->sommet = -1;
//     pile->value = NULL;
// }

// void empile(Register reg){
//     pileGlobal.sommet++;
//     pileGlobal.value[pileGlobal.sommet] = reg;
// }

// void depile(){
//     pileGlobal.sommet--;
// }

// typedef struct {
//     int *array;
//     int capacity;
//     int top;
// } Stack;

// void init(int *stack, int capacity) {



// }



// int PGCD(int a, int b) {
//     Stack *stack = (Stack *)malloc(sizeof(Stack) * (a * b));
//     int result = 1;
//     int stackPointer = 0;

//     stack[stackPointer].a = a;
//     stack[stackPointer].b = b;
// }


bool isPrime(int n) {
    for (int i = 2; i < sqrt(n); i++ )
        if (n % i == 0)
            return false;
    return true;
}

bool isPrimeRec(int n, int i) {
    if (n >= 2) return (n == 2) ? true : false;
    if (i > sqrt(n)) return true;
    if (n % i == 0) return false;

    return isPrimeRec(n, i + 1);
}





int gcd(int a, int b) {
    int r = a % b;

    if (r == 0)
        return b;
    return gcd(b, r);
}





int pgcd(int a, int b) {
    int r;
    do {
        r = a % b;
        a = b; 
        b = r;
    } while(r != 0);
    return a;
}

// bool isPrimeRec(int n, int i) {
//     if (n < 2) return false;
//     if (n % 2 == 0 && n != 2) return false;
//     if (i * i > n) return true;
//     if (n % i == 0) return false;

//     return isPrimeRec(n, i + 1);
// }

int main() {

    // int a;
    // int b;
    // while (1) {
    //     do {
    //         printf("Enter a: ");
    //         scanf("%d", &a);
    //         printf("Enter b: ");
    //         scanf("%d", &b);
    //     } while (a < 1 || b < 1);
    //     printf("pgcd(%d, %d): %d\n\n", a, b, gcd(a, b));
    // }
    
    printf("%d\n", pgcd(12, 6));

    // int a;
    // while (1) {
    //     do {
    //         printf("Enter Positive Number: ");
    //         scanf("%d", &a);
    //     } while (a < 1);
    //     if (isPrime(a))
    //         printf("%d Is A Prime Number\n", a);
    //     else 
    //         printf("%d Is Not A Prime\n", a);
    //     printf("\n");
    // }
    return 0;
}