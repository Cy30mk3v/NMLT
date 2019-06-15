#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>

int main()
{
	char lower_a = 'a';
	char lower_m = 'm';

	printf("Minimum char = %i, ",CHAR_MIN);
	printf("Maximum char = %i\n", CHAR_MAX);

	printf("Sau '%c' la '%c' \n", lower_a, lower_a + 1);
	printf("Ki tu in hoa '%c'\n", lower_m - 'a' + 'A');
	return 0;
}