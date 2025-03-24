#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define LINE 1024

void load_env(const char *path) {
    FILE *fptr = fopen(path, "r");
    if (!fptr) {
        perror("Failed to open .env file");
        return;
    }

    char line[LINE];
    while (fgets(line, sizeof(line), fptr)) {
        char *key = strtok(line, "=");
        char *value = strtok(NULL, "\n");
        if (key && value) 
            _putenv_s(key, value);
        }
    fclose(fptr);
}

int gcd(int a, int b) {
    if (b == 0) 
        return a;
    return gcd(b, a % b);
}

void generateKey(long long *e, long long *d, long long *n) {
    load_env(".env");
    int p = atoi(getenv("p"));
    int q = atoi(getenv("q"));
    *n = p * 1LL * q;
    int phi = (p - 1) * (q - 1);
    int temp = 2;
    while (temp < phi) {
        if (gcd(temp, phi) == 1)
            break;
        temp++;
    }
    *d = (long int) pow(*e, -1) % phi;
}

long long encrypt(long long m, long long e, long long n) {
    return (long long) pow(m, e) % n;
}

long long decrypt(long long c, long long d, long long n) {
    return (long long) pow(c, d) % n;
}

int main() {

    long long e, n, d;
    long int m = 4323456;
    generateKey(&e, &d, &n);
    printf("e: %d\nn: %d\nd: %d\n",e,n,d);
    long long c = encrypt(m, e, n);
    printf("emessage: %lf\n", c);
    long long f = decrypt(c, d, n);
    printf("dmessage: %lf\n", f);

    return 0;
}