#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int i, j = 5;
	i = ++j;
	printf("i=%d, j=%d\n", i, j);
	j = 5;
	i = j++;
	printf("i=%d, j=%d\n", i, j);
	return 0;
}