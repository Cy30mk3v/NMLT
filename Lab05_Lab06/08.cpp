/*
HO TÊN: VÕ TRẦN CHÍ HƯNG
MSSV: 1753058
*/

#include <stdio.h>
#include <math.h>

int check_input_data(int a);
void convert_decimal_to_binary(int n);
int recursion(int a);

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
	printf("%i\n", recursion(a));
}

int check_input_data(int a)
{
	if (a >= 0)
		return 1;
	else return 0;
}
void convert_decimal_to_binary(int a)
{
	while (a>0)
	{
		if (a % 2 == 0)
			printf("0");
		if (a % 2 != 0)
			printf("1");
		a = a / 2;
	}
}

int recursion(int a)
{
	if (a == 0 || a == 1)
		return a;
	printf("%i", recursion(a / 2));
	return a % 2;
}



