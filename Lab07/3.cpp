/*
HỌ TÊN: VÕ TRẦN CHÍ HƯNG
MSSV: 1753058
*/

#include <stdio.h>
void get_array(int n, int A[]);
void print_array(int n, int A[]);
void search(int n, int A[], int k);

int main (void)
{
	int A[100];
	int n, k;
	printf("Nhap so phan tu cua mang: ");
	scanf_s("%i", &n);
	get_array(n, A);
	print_array(n, A);
	printf("Nhap vao so can tim: ");
	scanf_s("%i", &k);
	search(n, A, k);
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

void search(int n, int A[], int k)
{
	for (int i = 0; i < n; i++)
	{
		if (A[i] == k)
		{
			printf("So nhap vao ung voi vi tri: %i\n", i+1);
		}
		break;
	}
	printf("-1\n");
}
		