//снять k-ый бит числа 
#include <stdio.h>
#pragma warning (disable:4996);

int clearkBit(int a, int k) {
    return ((~(1 << k)) & a);
}

int main() {
    int a, k, result;

    printf("Enter a number ");
    scanf("%d", &a);

    printf("Enter a bit ");
    scanf("%d", &k);

    result = clearkBit(a, k);
    printf("%d", result);

    return 0;
}