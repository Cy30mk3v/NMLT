/*
HỌ TÊN: VÕ TRẦN CHÍ HƯNG
MSSV: 1753058
*/

#include <stdio.h>
void get_array(int n, int A[]);
void remove(int n, int A[], int k);
void print_array(int n, int A[]);

int main (void)
{
	int A[100];
	int n, k, x;
	printf("Nhap so phan tu cua mang: ");
	scanf_s("%i", &n);
	get_array(n, A);
	print_array(n, A);
	printf("Nhap vi tri can xoa: ");
	scanf_s("%i", &k);
	while (k<0 || k >(n-1))
	{
		printf("So nhap vao da sai, hay nhap lai: ");
		scanf_s("%i", &k);
	}
	remove(n, A, k-1);
	print_array(n-1, A);
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
void remove(int n, int A[], int k)
{
	for (int i =k; i<n-1; i++)
	{
		A[i] = A[i + 1];
	}
	n--;
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