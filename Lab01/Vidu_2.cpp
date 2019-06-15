#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int a, b;
	printf("Nhap 2 so nguyen:");
	scanf("%i %i", &a, &b);
	printf("%i - %i = %i", a, b, a - b);
}