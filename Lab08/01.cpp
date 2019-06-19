/*
HỌ TÊN: VÕ TRẦN CHÍ HƯNG
MSSV: 1753058
*/

#include <stdio.h>
#include <stdlib.h>
void arrange(int n, int A[]);
void get_array(int n, int A[]);
void print_array(int n, int A[]);

int main(void)
{
	int n;
	printf("Nhap so phan tu cua mang: ");
	scanf_s("%d", &n);
	while (n<1)
	{
		printf("So nhap vao da sai, hay nhap lai: ");
		scanf_s("%d", &n);
	}
	int *pa = new int[n];
	if (pa != NULL)
	{
		get_array(n, pa);
		print_array(n, pa);
		arrange(n, pa);
		print_array(n, pa);
	}
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

void arrange(int n, int A[])
{
	int i, j;
	for (i = 0; i<n - 1; i++)
		for (j = i + 1; j<n; j++)
			if (A[i]>A[j])
			{
				int temp = A[i];
				A[i] = A[j];
				A[j] = temp;
			}
}

void print_array(int n, int A[])
{
	if (n == 0)
	{
		printf("Mang rong");
	}
	else
	{
		for (int i = 0; i < n - 1; i++)
			printf("%i", A[i]);
	}
	printf("%i", A[n - 1]);
	printf("\n");
}