/*
HO TÊN: VÕ TRẦN CHÍ HƯNG
MSSV: 1753058
*/

#include <stdio.h>
#include <math.h>

void check_palindromic_number(long int a);
int main(void)
{
	long int a;
	printf("Nhap so nguyen (< 2 ty): ");
	scanf_s("%li", &a);
	while (a > 2000000000)
	{
		printf("So nhap vao da sai, nhap so nguyen (< 2 ty):");
		scanf_s("%li", &a);
	}
	check_palindromic_number(a);
}
void check_palindromic_number(long int a)
{
	int rev, b, c, pn;
	for (int i = 1; i < a; i++)
	{
		b = a;
		rev = 0;
		while (b > 0)
		{
			c = b % 10;
			rev = 10 * rev + c;
			b /= 10;
		}
		pn = (rev == a ? 1 : 0);
	}
	printf("%i\n", pn);
}