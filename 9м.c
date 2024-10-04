//Дано 2𝑝 разрядное целое число.«Поксорить» все биты этого числа друг с другом.Пример.101110001 → 1; 11100111 → 0.
#include <stdio.h>

//посчитать кол-во разрядов двоичного числа
int dg(int number) {
	int p;
	for (p = 0; number != 0; p++) {
		number /= 2;
	}
	return p;
}

int main() {
	int number, p, opxor;

	printf("Enter the number ");
	scanf_s("%d", &number);

	
	p = dg(number);// кол-во символов в дв числе
	if (p == 1) {
		printf("Enter a number greater them");
	}
	else {
		opxor = (number & 1) ^ ((number >> 1) & 1);//xor 0 и 1 битов
		number >>= 1;
		while (p!=0) {//перебор битов числа, ограниченное p кол-вом знаков
			opxor^= (number>>1)&1;//xor со следующим битом
			number >>= 1;
			p-= 1; 
			}
	printf("%d", opxor);
	return 0;
		}

	}
	
	
	