/*
HỌ TÊN; VÕ TRẦN CHÍ HƯNG
MSSV; 1753058
*/

#include <stdio.h>
void get_array(int n, int A[]);
void print_array(int n, int A[]);
void insert(int n, int A[], int x, int k);

int main(void)
{	
	int A[100];
	int n, k, x;
	printf("Nhap so phan tu cua mang: ");
	scanf_s("%i", &n);
	get_array(n, A);
	print_array(n, A);
	printf("Nhap vi tri cua so can them vao mang:");
	scanf_s("%i", &k);
	while ((k<0) || (k>10))
	{
		printf("Vi tri nhap vao da sai, hay nhap lai: ");
		scanf_s("%i", &k);
	}
	printf("Nhap gia tri can them vao mang: ");
	scanf_s("%i", &x);
	insert(n, A, x, k);
	print_array(n+1, A);
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

void print_array(int n, int A[])
{
	if (n==0)
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


void insert(int n, int A[], int x, int k)
{
	for (int i = n; i>=k; i--)
	{
		A[i ] = A[i-1];
	}
	A[k] = x;
	++n;
}