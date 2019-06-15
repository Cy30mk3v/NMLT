#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int degree;
	printf("Nhap do lon cua goc: ");
	scanf("%i", &degree);
	printf("%i\n", (degree / 90)+1);
}