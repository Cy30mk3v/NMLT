#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	long big;

	printf("\"big\" is %u bytes\n", sizeof(big));
	printf("a short is %u bytes\n", sizeof(short));
	printf("a double is %u bytes\n", sizeof(double));

	return 0;
}