/*
HO TÊN: VÕ TRẦN CHÍ HƯNG
MSSV: 1753058
*/

#include <stdio.h>
#include <math.h>

int check_primes_number(int a);
int main(void)
{
	long int a, b, c;
	printf("Nhap so chu so nguyen to can in: ");
	scanf_s("%li", &a);
	while (a <= 0 || a > 2000)
	{
		printf("So nhap vao da sai, hay nhap lai: ");
		scanf_s("%li", &a);
	}
	c = 2;
	b = 0;
	while (b < a)
	{
		if (check_primes_number(c))
		{
			printf("%i ", c);
			b++;
		}
		c++;
	}
	printf("\n");
}
int check_primes_number(int a)
{
	for (int i = 2; i <= sqrt(a); i++)
		if (a%i == 0)
			return 0;
	return 1;
}
