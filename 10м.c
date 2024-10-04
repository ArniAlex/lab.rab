//Написать макросы циклического сдвига в 2𝑝 разрядном целом числе на 𝑛 бит влево и вправо.
#include <stdio.h>

//сколько разрядов в двоичном пр. числа
int position(unsigned int num) {
	int p;
	for (p = 0; num != 0; p++) {
		num/= 2; 
	}
	return p;
}

//алгоритм возведения в степень 
int st(int base, int ex) {
	int res=1;
	for (int f = 0; f < ex; f++) {
		res*= base;
	}
	return res;
}



//макросы
#define LEFT(num, n) ((num << n) | (num >> (position(num) - n))) //двигаем на n бит влево и в появ нули устанавливаем начало числа, которое стёрли
#define RIGHT(num, n) ((num >> n) | (num << (position(num) - n)))

int main() {
	unsigned int num;
	int n, k;//k-указатель поворота
	int p;

	printf("Enter a number ");
	scanf_s("%u", &num);

	p = position(num);//кол-во двоичных символов в числе

	printf("Enter a number of bit ");
	scanf_s("%d", &n);//сдвиг числа на n позиций

	printf("If you want move the number to the left: enter 1 \nIf you want move the number to the right: enter 0\n");
	scanf_s("%d", &k);//определяет направление движения

	if (k == 0 || k==1) { //при условии, что введённые значения верные 
		if (k == 1) {
			num = LEFT(num, n);
		}
		else {
			num = RIGHT(num, n);
		}
		num &= st(2, p) - 1;//удаление битов за пределами длины нач. числа
		printf("num result %d", num);
	}

	else {
		printf("Enter a different value ");
	}
	
	return 0;
}