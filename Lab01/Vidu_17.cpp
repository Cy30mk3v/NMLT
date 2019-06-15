#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)

{

	int i = 0, j, k = 7, m = 5, n;

	j = m += 2;

	printf("j = %d\n", j);

	j = k++ > 7;

	printf("j = %d\n", j);

	j = i == 0 & k;

	printf("j = %d\n", j);

	n = !i > k >> 2;

	printf("n = %d\n", n);

	return 0;

}