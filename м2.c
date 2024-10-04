//вывести на экран k-ый бит числа a
#include<stdio.h>

int ft(int a, int k)
{
    return (a & (1 << k)) >> k;
}
int main() {
    int a, k, b;

    printf("Enter a number ");
    scanf_s("%d", &a);

    printf("Enter a bit ");
    scanf_s("%d", &k);

    b = ft(a, k);
    printf("%d", b);
    return 0;
}