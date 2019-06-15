#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>

int main()
{
	unsigned long big= ULONG_MAX;

	printf("Minimum int = %i\n", INT_MIN);
	printf("Maximum int = %i\n", INT_MAX);
	printf("Maximum unsigned =%u\n", UINT_MAX);
	printf("Maximum long int = %li\n", LONG_MAX);
	printf("Maximum unsigned long= %lu\n", big);
	return 0;
}