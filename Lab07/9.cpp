/*
HỌ TÊN; VÕ TRẦN CHÍ HƯNG
MSSV; 1753058
*/

#include <stdio.h>
void get_array(int n, int A[]);
void print_array(int n, int D[]);
int check_array(int n, int A[]);
void insert(int n, int A[], int x, int k);
void arrange(int n, int A[]);

int main(void)
{
	int n, a;
	int A[100];
	printf("Nhap so phan tu cua mang: ");
	scanf_s("%i", &n);
	get_array(n, A);
	while (check_array(n, A) == 0)
	{
		printf("Mang nhap vao khong dung thu tu, hay nhap lai: ");
		get_array(n, A);
	}
	printf("Nhap so muon them vao mang: ");
	scanf_s("%i", &a);
	insert(n, A, a, 0);
	arrange(n+1, A);
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

void insert(int n, int A[], int x, int k)
{
	for (int i = n; i >= k; i--)
	{
		A[i] = A[i - 1];
	}
	A[k] = x;
	++n;
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