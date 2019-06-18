/*
HO TÊN: VÕ TRẦN CHÍ HƯNG
MSSV: 1753058
*/

#include <stdio.h>
#include <math.h>

int compute_factorial(int a);
int main(void)
{
	int a, b, c;
	printf("Nhap 2 so K va N (K<=N): ");
	scanf_s("%i %i", &a, &b);
	while ((a < 0) || (b < 0) || (a > b))
	{
		printf("So nhap vao da sai, nhap lai 2 so K va N (K<=N): ");
		scanf_s("%i %i", &a, &b);
	}
	c = a - b;
	printf("%i\n", compute_factorial(b) / (compute_factorial(a)*compute_factorial(b-a)));
}
int compute_factorial(int a)
{
	int result = 1;
	for (int i = 2; i <= a; i++)
	{
		result *= i;
	}
	return result;
}