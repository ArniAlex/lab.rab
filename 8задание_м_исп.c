//Найти максимальную степень 2 на которую делится данное целое число.Примечание.Операторами цикла пользоваться нельзя.
#include <stdio.h>
#pragma warning (disable:4996)

int st(unsigned int n) {

	if ((n&1) == 1) { 
		return 0;
	}
	return 1 + st(n >> 1);
}

int main() {
	unsigned int n=0;

	printf("Enter the number ");
	scanf("%u", &n);

	if (n == 0) {
		printf("Enter another number ");
		return 0;
	}

	int power = st(n);
	printf("The maximum degree is %d", power);
	return 0;
}