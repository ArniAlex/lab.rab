//обнулить младшие k бит в заданном слове
#include <stdio.h>

int clBit(int k, int n) {
	return ((n>>k)<<k);
}

int main() {
    int n, k ;

    printf("Enter a number ");
    scanf_s("%d", &n);

    printf("Enter the number of bits ");
    scanf_s("%d", &k);

    n = clBit(k, n);
    printf("The result is %d", n);
    return 0;
}