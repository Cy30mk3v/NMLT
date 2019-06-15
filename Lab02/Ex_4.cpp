#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char c;
	printf("Nhap chu cai: ");
	scanf("%c", &c);
	printf("%c", c&95);
}