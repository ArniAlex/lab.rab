//Поменять местами байты в заданном 32-х разрядном целом числе
#include <stdio.h>

// n-вводимое число, k-индекс байта, l-индекс другого байта

//получение байта
unsigned int gByte(unsigned int a, int k) {
    return (a>>(k*8) & 255);
}

//Очистка байта
unsigned int clByte(unsigned int a, int k) {
    return (a & (~(255 << (k * 8))));
}

//смена байт местами 
unsigned int exByte(unsigned int a, int k, int l) {
    int byte1, byte2;

    byte1 = gByte(a, k);
    byte2 = gByte(a, l);

    a = clByte(a, k);
    a = clByte(a, l);

    return (a | (byte1 << (l * 8)) | (byte2 << (k * 8)));
}

int main() {
    unsigned int a;
    int k, l;

    printf("Enter a number ");
    scanf_s("%u", &a);

    printf("Enter the position of first byte(0-3) ");
    scanf_s("%d", &k);

    printf("Enter the position of second byte(0-3) ");
    scanf_s("%d", &l);

    if (k < 0 || k>3 || l < 0 || l>3) {
        printf("The byte positions are incorrect ");
        return 1;
    }

    a = exByte(a, k, l);
    printf("The result of the byte exchange %u", a);

    return 0;
}