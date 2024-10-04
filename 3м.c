//установить k-ый бит числа a
#include <stdio.h>
int setkBit(int a, int k)
{
	return ((1 << k) | a);
}

int main() {
	int a, k, result;

	printf("Enter a number ");
	scanf_s("%d", &a);

	printf("Enter a bit ");
	scanf_s("%d", &k);

	result = setkBit(a, k);
	printf("Result %d", result);

	return 0;
}