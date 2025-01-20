#include <stdio.h>

int main(void) {
    int a = 5;

    int *ptr = &a;
    *ptr = 100;

    return 0;
}
