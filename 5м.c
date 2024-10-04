//поменять местами i и j бита числа a
#include <stdio.h>

//смена бит местами
int chBits(int i, int j, int bit1, int bit2, int a) {
	bit1 = (a >> i) & 1;//получаем i бит а 
	bit2 = (a >> j) & 1;//получаем j бит а 

	a = a&~(1<<i)&~(1<<j);//удаляем эти биты из числа
	return (a|(bit1<<j)|(bit2<<i));//ставим биты накрест
}

int main() {
	int i, j, bit1=0, bit2=0, a;
	
	printf("Enter the number ");
	scanf_s("%d", &a);

	printf("Enter the first bit ");
	scanf_s("%d", &i);
	printf("Enter the second bit ");
	scanf_s("%d", &j);

	if (i == j) {
		printf("The result is %d", a);
	}
	else {
		printf("The result is %d", chBits(i, j, bit1, bit2, a));
	}
	return 0;
}