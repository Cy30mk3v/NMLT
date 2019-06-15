#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int i = 5, j = 4;
	double f;

	f = (double)i / j;
	printf("%f ", f);
	f = i / (double)j;
	printf("%f ", f);
	f = (double)i / (double)j;
	printf("%f ", f);
	f = (double)(i / j);
	printf("%f ", f);
	return 0;

}