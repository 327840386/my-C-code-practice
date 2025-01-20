#include <stdio.h>

long power(int base,  int n) {
    long int result = 1;
    for (int i = 0; i < n; i++) {
        result *= base;
    }
    return result;
}

int main() {
    for (int i = 1; i <= 10; i++) {
        long int result = power(2, i);
        printf("2 to the power of %u is: %ld\n", i, result);
    }

    return 0;
}
