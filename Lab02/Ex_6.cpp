#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{

	int n, n1, n2, n3;
	printf("Nhap 3 chu so: ");
	scanf("%i", &n);
	//Số hàng trăm
	n1=n/100;
	//Số hàng chục
	n2=(n-(n1*100))/10;
    	//Số hàng đơn vị
	n3=(n-(n1*100)-(n2*10));
	printf("%i\n", n1 + n2 + n3);
}
