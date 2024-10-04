//A    «Склеить» первые 𝑖 битов с последними 𝑖 битами из целого числа длиной 𝑙𝑒𝑛 битов.
//B    Получить биты из целого числа длиной 𝑙𝑒𝑛 битов, находящиеся между первыми 𝑖 битами и последними 𝑖 битами
#include<stdio.h>
#pragma warning(disable:4996)

//функция вычисления степени
int deg(int base, int ex) {
    int degr = 1;
    for (int f = 0; f < ex; f++) {
        degr *= base;
    }
    return degr;
}
// функция вычисления длины двоичного предст. числ а
int lenbin(unsigned int num) {
    int p;
    for (p = 0; num != 0; p++) {
        num /= 2;
    }
    return p;
}

int main()
{
    unsigned int num, num2;
    int len, i, result, resultB;

    printf("Enter a number ");
    scanf("%u", &num);
    printf("Enter a numberoof bit ");
    scanf("%d", &i);

    len = lenbin(num);

    //A
    num2 = num & (deg(2, i) - 1);//последнме i бит

    result = (num  & ~(deg(2, len-i)-1));//вырезка из первых i цифр слева и нулей далее
    result >>= (len - 2 * i);
    result |= num2;

    printf(" The result in A: %d", result);

    //B
    resultB = num >> i;
    resultB &= deg(2, len - 2 * i) - 1;
    printf(" The result in B: %d", resultB);

    return 0;

}