#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int n1, n2;
	printf("Nhap so thu nhat: ");
	scanf("%i", &n1);
	printf("Nhap so thu hai: ");
	scanf("%i", &n2);
	printf("So lon hon la: %i", (n1 > n2) ? n1 : n2);
}