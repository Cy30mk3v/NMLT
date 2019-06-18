/*
HO TÊN: VÕ TRẦN CHÍ HƯNG
MSSV: 1753058
*/

#include <stdio.h>
#include <math.h>
int check_input_data(int a);
int fibo(int a);

int main(void)
{
	int a;
	printf("Nhap so nguyen khong am N:");
	scanf_s("%i", &a);
	while (check_input_data(a) == 0)
	{
		printf("So nhap vao da sai, hay nhap lai: ");
		scanf_s("%i", &a);
	}
	int print_fibo = fibo(a);
	printf("%i\n", print_fibo);
}

int check_input_data(int a)
{
	if (a >= 0)
		return 1;
	else return 0;

}

int fibo(int a)
{
	if (a == 0)
		return 0;
	else
	{
		if (a == 1 || a == 2)
			return 1;
		else return fibo(a - 1) + fibo(a - 2);
	}

}