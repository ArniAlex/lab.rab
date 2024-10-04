//вывести на экран младший бит числа a 
#include <stdio.h> 

int main() {
	int a, b;

	printf("Enter a number ");
	scanf_s("%d", &a);

	while (a > 0) {
		b = a % 2;
		a /= 2;
	}

	printf("The lowerest bit of the number a is %d", b);

	return 0;
}
