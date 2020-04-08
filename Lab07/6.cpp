
#include <cstdio>



void get_array(int n, int A[]);
void print_array(int n, int D[]);
void add_array(int A[], int& a, int B[], int& b, int C[], int& c);
void print_arrayOnlyOdd(int n, int D[]);
void print_arrayOnlyEven(int n, int D[]);
void count(int& odd, int& even, int A[], int n);


int main(void)
{
	int a, b, c;
	int A[100];
	int B[100];
	int C[100];
	printf("Nhap so phan tu cua mang: ");
	scanf("%i", &a);
	get_array(a, A);
	print_array(a, A);
	int odd, even;
	count(odd, even, A, a);
	if (odd == 0 && even > 0) {

		print_arrayOnlyEven(a, A);
	}
	if (even == 0 && odd > 0) {
		print_arrayOnlyOdd(a, A);
	}
	if (even > 0 && odd > 0)
	{
		printf("\n");
		for (int i = 0; i < a; i++) {
			if (A[i] % 2 == 0) {
				printf("%i", A[i]);
			}
		}
		printf("|");
		for (int i = 0; i < a; i++) {
			if (A[i] % 2 != 0) {
				printf("%i", A[i]);
			}
		}
		printf("\n");
	}
	if (even + odd == 0) {
		printf("\nMang rong|Mang rong\n");
	}
}


void count(int& odd, int& even, int A[], int n) {
	odd = even = 0;
	for (int i = 0; i < n; i++)
	{
		if (A[i] % 2 == 0)
			even++;
		else
			odd++;
	}
}
void get_array(int n, int A[])
{
	while (n < 1 || n>10)
	{
		printf("So nhap vao da sai, hay nhap lai: ");
		scanf("%i", &n);
	}
	for (int i = 0; i < n; i++)
	{
		printf("Nhap a[%i]:", i);
		scanf("%i", &A[i]);
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

void print_arrayOnlyEven(int n, int D[])
{
	if (n == 0)
	{
		printf("Mang rong");
		return;
	}
	else
	{
		printf("\nMang rong|");
			for (int i = 0; i < n - 1; i++)
				printf("%i", D[i]);
	}
	printf("%i\n", D[n - 1]);
	printf("\n");
}

void print_arrayOnlyOdd(int n, int D[])
{
	if (n == 0)
	{
		printf("Mang rong");
		return;
	}
	else
	{
		printf("\n");
		for (int i = 0; i < n - 1; i++)
			printf("%i", D[i]);
	}
	printf("%i", D[n - 1]);
	printf("|Mang rong\n");
		printf("\n");
}
void add_array(int A[], int& a, int B[], int& b, int C[], int& c)
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
