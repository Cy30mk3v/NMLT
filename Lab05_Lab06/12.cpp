/*
HO TÊN: VÕ TRẦN CHÍ HƯNG
MSSV: 1753058
*/

#include <stdio.h>
#include <math.h>

void check_palindromic_number(long int a);
int main(void)
{
	long int a;
	printf("Nhap so nguyen (< 2 ty): ");
	scanf("%li", &a);
	while (a > 2000000000)
	{
		printf("So nhap vao da sai, nhap so nguyen (< 2 ty):");
		scanf("%li", &a);
	}
	check_palindromic_number(a);
}
void check_palindromic_number(long int a)
{
	//Reverse, last digit, copy number
	long int rev, l, copy;
	int pn;
	copy = a;
	rev = 0;
	while(copy){
		//Get last digit of number
		l = copy%10;
		//Add to reverse
		rev = rev *10 + l;
		//The number remove last digit
		copy/=10;
	}
	//Check if reverse and original is the same
	pn = (rev == a)? 1:0;
	printf("%i\n", pn);
}
