//Разработать консольное приложение, шифрующее и дешифрующее файл с использованием введенного ключа. Алгоритм шифрования: простой «xor».
#include <stdio.h>
#include <string.h>
#pragma warning (disable:4996)

/*1. организовать считывание строчек с консоли в файл в отдельной функции
* 2. в отдельных функциях шифорование и дешифрование
* 3. в мейн считать ключ и спросить у пользователя какую ф хочет выполнять
*/

//1 пункт
void numToFile(const char* ourfile) {
	FILE* fl = fopen(ourfile, "w");//открываем файл для записи

	if (fl == NULL) {
		printf("Openning error ");
		return 10;
	}

	char enterString[BUFSIZ];

	printf("Enter the string ");
	scanf("%s", enterString);
	fprintf(fl, "%s", enterString);

	fclose(fl); //закрываем файл
}

//2.шифруем и дешифруем

//шифруем
int encryption(char*infile, char* outfile, char* key) {

	FILE* fl; //указатель на файл
	FILE* fl2;
	int lnkey = strlen(key);//функция из др. библиотеки 
	int i = 0;
	char y;

	fl = fopen(infile, "r+");//открытие для чтения и записи без изм размера
	fl2 = fopen(outfile, "w"); //открытие для записи
	
	if (fl == NULL|| fl2==NULL) {
		printf("Openning error ");
		return 100;
	}
	while ((y = fgetc(fl)) != EOF) { //чтение символов из файла, работает до конца файла
		y ^= key[i % lnkey]; //для повторения ключа короче файла
		fputc(y, fl2);//записываем переменную в файл   
		i++;
	}

	fclose(fl);//закрывает файл
	fclose(fl2);
	printf("The file is encrypted");
	return 0;
}


int main() {
	FILE* fl; 
	fl= fopen("infile.txt", "r+");//задано имя входного файла
	char key[100];
	char sin[100], sout[100];

	printf("Enter the key: ");
	scanf("%s", key);

	printf("Enter input file name for operation: ");//имя выходного файла
	scanf("%s", sin);

	printf("Enter output file name for operation: ");//имя выходного файла
	scanf("%s", sout);

	numToFile(sin);//строчка с клавиатуры во входной файл

	encryption(sin, sout, key);
	return 0;
}
