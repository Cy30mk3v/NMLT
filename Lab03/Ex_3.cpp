#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int n;
	do {
		printf("Nhap chieu cao tuong: ");
		scanf("%i", &n);
	} while (n < 1 || n>20);
	for (int i = 0; i < n; i++)
	{
		int j = 0;
		for (j; j < n - i-1; j++)
		{
			printf(" ");
		}
		for (j; j < n; j++)
		{
			printf("#");
		}
		printf("  ");
		for (int k = i; k >=0; k--)
		{
			printf("#");
		}
		
		printf("\n");
	}
}


