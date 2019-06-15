#define _CRT_SERCURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int dec = 20, oct = 020, hex = 0x20;

	printf("dec = %d, oct = %d, hex=%d\n", dec, oct, hex);
	printf("dec = %d, oct = %o, hex=%x\n", dec, oct, hex);
}