/*
HO TÊN: VÕ TRẦN CHÍ HƯNG
MSSV: 1753058
*/

#include <stdio.h>
#include<conio.h>

int count(unsigned long n);
int happy_number(unsigned long n);

int main(void)
{
	unsigned long n;
	printf("Nhap so can kiem tra: ");
	scanf_s("%i", &n);
	while (n < 0)
	{
		printf("So nhap vao da sai, hay nhap lai: ");
		scanf_s("%li", &n);
	}
	if (happy_number(n))
	{
		printf("So tren la so hanh phuc\n");
	}
	else printf("So tren khong phai la so hanh phuc\n");
	_getch();
}

int count(unsigned long n)
{
	int a = 0;
	while (n > 0)
	{
		a++;
		n /= 10;
	}
	return a;
}

int happy_number(unsigned long n)
{
	if (count(n) % 2 != 0) 
		return 0;
	int i = 0;
	float s = 0, m = 0;
	while (n > 0)
	{
		if (i <= count(n) / 2)
		{
			m += n % 10;
		}
		s += n % 10;
		n /= 10;
		i++;
	}
	if (m * 2 == s) 
		return 1;
	else 
		return 0;
}