/*
HỌ TÊN; VÕ TRẦN CHÍ HƯNG
MSSV; 1753058
*/

#include <stdio.h>
void get_array(int n, int A[]);
void print_array(int n, int D[]);
int check_array(int n, int A[]);
void add_array(int A[], int &a, int B[], int &b, int C[], int &c);
void arrange(int n, int A[]);

int main(void)
{
	int n1, n2, n3;
	int A[100];
	int B[100];
	int C[100];
	printf("Nhap so phan tu cua mang thu nhat: ");
	scanf_s("%i", &n1);
	get_array(n1, A);
	while ((check_array(n1, A)) == 0)
	{
		printf("Mang nhap vao khong dung thu tu, hay nhap lai: ");
		get_array(n1, A);
	}
	printf("Nhap so phan tu cua mang thu hai: ");
	scanf_s("%i", &n2);
	get_array(n2, B);
	while ((check_array(n2, B)) == 0)
	{
		printf("Mang nhap vao khong dung thu tu, hay nhap lai: ");
		get_array(n2, B);
	}
	add_array(C, n3, B, n2, A, n1);
	arrange(n3, C);
	print_array(n3, C);
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

int check_array(int n, int A[])
{
	for (int i = 0; i<n - 1; i++)
	{
		if (A[i] > A[i + 1])
		{
			return 0;
			break;
		}
		else return 1;
	}
	if (n == 1)
		return 1;
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