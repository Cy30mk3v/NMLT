#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <string>

int main()
{
	int n;
	printf("Nhap so: ");
	scanf("%i", &n);
	const char* c[11] = { "Mot","Hai","Ba","Bon","Nam","Sau","Bay","Tam","Chin","Muoi"};
	const char* c1 [10] = { "mot","hai","ba","bon","lam","sau","bay","tam","chin" };
	int n1 = n % 10;
	int n2 = (n-n1)/10;
	if(n>19)
	{
		printf("%s muoi %s\n", c[n2-1], c1[n1-1]);
		return 0;
	}
	if (n <= 10)
	{
		printf("%s\n",c[n1-1]);
		return 0;
	}
	printf("Muoi %s\n", c1[n1-1]);
	
}