#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int n1, n2;
	printf("Nhap do dai 2 canh hinh chu nhat: ");
	scanf("%i %i", &n1, &n2);
	printf("%i %i\n", (n1 + n2) * 2, n1 * n2);
}