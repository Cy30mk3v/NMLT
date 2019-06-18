/*
HỌ TÊN; VÕ TRẦN CHÍ HƯNG
MSSV; 1753058
*/

#include <stdio.h>
void get_array(int n, int A[]);
void print_array(int n, int D[]);
void add_array(int A[], int &a, int B[], int &b, int C[], int &c);

int main (void)
{
	int a, b, c;
	int A[100];
	int B[100];
	int C[100];
	printf("Nhap so phan tu cua mang thu nhat: ");
	scanf_s("%i", &b);
	get_array(b, B);
	print_array(b, B);
	printf("Nhap so phan tu cua mang thu hai: ");
	scanf_s("%i", &c);
	get_array(c, C);
	print_array(c, C);
	add_array(A, a, B, b, C, c);
	print_array(a, A);
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
		return;
	}
	else
	{
		for (int i = 0; i < n - 1; i++)
			printf("%i", D[i]);
	}
	printf("%i", D[n - 1]);
	printf("\n");
}

void add_array(int A[], int &a, int B[], int &b, int C[], int &c)
{
	int i;
	a = 0;
	for (i = 0; i < b; i++)
	{
		A[a++] = B[i];
	}
	for (i = 0; i < c; i++)
	{
		A[a++] = C[i];
	}
}