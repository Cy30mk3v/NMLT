﻿/*
HỌ TÊN; VÕ TRẦN CHÍ HƯNG
MSSV; 1753058
*/

#include <stdio.h>
void get_array(int n, int A[]);
void print_array(int n, int A[]);
void arrange(int n, int A[]);

int main (void)
{
	int A[100];
	int n;
	printf("Nhap so phan tu cua mang: ");
	scanf_s("%i", &n);
	get_array(n, A);
	print_array(n, A);
	arrange(n, A);
	printf("\n");
	print_array(n, A);
	printf("\n");
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
}

void arrange(int n, int A[])
{
	int i, j;
	for (i=0;i<n-1; i++)
		for (j=i+1; j<n;j++)
			if (A[i]>A[j])
			{
				int temp = A[i];
				A[i] = A[j];
				A[j] = temp;
			}
}