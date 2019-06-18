/*
HO TÊN: VÕ TRẦN CHÍ HƯNG
MSSV: 1753058
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int USCLN(int e, int f);
void Cong_phan_so(int tu_1, int mau_1, int tu_2, int mau_2, int *Tu, int *Mau);
void Rut_gon(int *tu_r, int *mau_r);

int main(void)
{
	int a, b, c, d, tu, mau;
	printf("Nhap 2 phan so can tinh: ");
	scanf_s("%i/%i  %i/%i", &a, &b, &c, &d);
	while (b == 0 || d == 0)
	{
		printf("So nhap vao da sai, hay nhap lai: ");
		scanf_s("%i/%i  %i/%i", &a, &b, &c, &d);
	}
	Cong_phan_so(a, b, c, d, &tu, &mau);
	Rut_gon(&tu, &mau);
	if (tu*mau < 0)
	{
		tu = abs(tu);
		mau = abs(mau);
		printf("-%i/%i", tu, mau);
	}
	else printf("%i/%i", tu, mau);
	return 0;
}

int USCLN(int a, int b)
{
	a = abs(a);
	b = abs(b);
	while (a != b)
		if (a > b)
			a = a - b;
		else b = b - a;
		return a;
}
void Cong_phan_so(int tu_1, int mau_1, int tu_2, int mau_2, int *Tu, int *Mau)
{
	*Tu = (tu_1*mau_2) + (tu_2*mau_1);
	*Mau = (mau_1*mau_2);
}
void Rut_gon(int *tu_r, int *mau_r)
{
	int uoc;
	uoc = USCLN(*tu_r, *mau_r);
	*tu_r = *tu_r / uoc;
	*mau_r = *mau_r / uoc;
}