#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int i, j=10, k = 28;

	i = ((j > 5) && (k < 100) || (k > 24));
	printf("%i", i);
}