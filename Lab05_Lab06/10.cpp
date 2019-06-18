#include <stdio.h>

void change_number_to_prime_factors(int n);

int main()
{
	int n;
	printf("Nhap so nguyen duong N > 1: ");
	scanf_s("%i", &n);
	while (n <= 1)
	{
		printf("So nhap vao sai, nhap lai so nguyen duong N > 1");
		scanf_s("%i", &n);
	}
	change_number_to_prime_factors(n);
	printf("\n");

}

void change_number_to_prime_factors(int n)
{
	for (int i = 2; (n > 1);)
	{
		if (n %i == 0)
		{
			printf("%i ", i);
			n = n / i;
		}
		else i++;
	}
}