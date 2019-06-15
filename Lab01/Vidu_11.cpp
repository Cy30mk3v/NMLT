#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	short a = 0x6eb9;
	short b = 0x5d27;
	unsigned short c = 7097;

	printf("0x%x, ", a & b);
	printf("0x%x, ", a | b);
	printf("0x%x\n", a ^ b);

	printf("%u, ",c << 2);
	printf("%u\n", c >> 1);
	return 0;

}