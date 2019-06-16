#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main()
{
	float nf;
	printf("Nhap so tien can phai tra (dollar): ");
	scanf("%f", &nf);
	nf *= 1000;
	nf=round(nf);
	
	int n = nf/10;
	
	int n1 = n / 25; //So dong 25 cent 
	int n2 = (n - (25 * n1))/10; //So dong 10 cent
	int n3 = (n - (25 * n1 + 10 * n2))/5; //So dong 5 cent
	int n4 = n - (n1 * 25 + n2 * 10 + n3 * 5); //So dong 1 cent
	printf("So luong dong 25 cent, 10 cent, 5 cent, 1 cent phai dung la: %i %i %i %i", n1, n2, n3, n4);
	return 0;

}