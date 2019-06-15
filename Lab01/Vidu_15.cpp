#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int i, j = 100, k = -1;
	i = (j > k) ? j : k;
	printf("%i\n", i);
	i = (j < k) ? j : k;
	printf("%i", i);
	return 0;
}