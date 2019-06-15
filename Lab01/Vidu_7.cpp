#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int i = 6, j = 4, k;
	double f = 5.0, g = 4.0, h;

	k = i / j;
	printf("%i ", k);
	h = f / g;
	printf("%i ", h);
	h = i / j;
	printf("%i ", h);
	return 0;
}