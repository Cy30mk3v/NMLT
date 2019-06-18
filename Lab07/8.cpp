/*
HỌ TÊN; VÕ TRẦN CHÍ HƯNG
MSSV; 1753058
*/

#include <stdio.h>
void get_array(int n, int A[]);
void print_array(int n, int D[]);
int check_array(int n, int A[]);

int main (void)
{
	int A[100];
	int n;
	printf("Nhap so phan tu cua mang: ");
	scanf_s("%i", &n);
	get_array(n, A);
	print_array(n, A);
	printf("\n%i\n",check_array(n, A));
}

void get_array(int n, int A[])
{
	while (n<1 || n>10)
	{
		printf("So nhap vao da sai, hay nhap lai: ");
		scanf_s("%i", &n);
	}
	for (int i = 0; i < n; i++)
	{
		printf("Nhap a[%i]:", i);
		scanf_s("%i", &A[i]);
	}
}

void print_array(int n, int D[])
{
	if (n == 0)
	{
		printf("Mang rong");
	}
	else
	{
		for (int i = 0; i < n - 1; i++)
			printf("%i", D[i]);
	}
	printf("%i", D[n - 1]);
	printf("\n");
}

int check_array(int n, int A[])
{
	bool flag = true;
	for (int i = 1; i < n; i++)
	{
		if (A[i - 1] > A[i])
		{
			flag = false;
			break;
		}
	}
	if (flag == false)
	{
		return 0;
	}
	return 1;
}
