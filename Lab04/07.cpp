/*
HỌ TÊN: VÕ TRẦN CHÍ HƯNG
MSSV: 1753058*/

//KHAI BÁO THƯ VIỆN
#include <stdio.h>
#include <math.h>

//KHAI BÁO CÁC HÀM
int check_input_data(int a);
int factorial(int a);
float result_A(int a);
float result_B(int a);
float result_C(int a);
long result_D(int a);
long result_E(int a);

//HÀM CHÍNH ĐỂ NHẬP VÀ IN RA MÀN HÌNH
int main (void)
{	
	int a;
	printf("Nhap so can tinh: ");
	scanf_s(" %i", &a);
	while (check_input_data == 0)
	{
		printf("So nhap vao da sai, hay nhap lai:");
		scanf_s("%i", &a);
	}
 	printf("Ket qua la: %f %f %f %i %f\n", result_A(a), result_B(a), result_C(a), result_D(a), result_E(a));
	
}

/*HÀM KIỂM TRA
ĐẦU VÀO:
a: số nguyên nhập vào để tính
ĐẦU RA: Cho biết số nhập vào có hợp lệ hay không
QUY ƯỚC: Nếu nhập đúng thì trả về 1, nếu nhập sai thì trả ra giá trị 0
*/

int check_input_data(int a)
{
	if (a < 0)
		return 0;
	else return 1;
}

//HÀM TÍNH GIAI THỪA
int factorial(int a)
{
	int result = 1;
	for (int i = 2; i <= a; i++)
	{
		result *= i;
	}
	return result;
}

//CÂU A
float result_A(int a)
{
	float result = 1;
	for (int i = 2; i <= a; i++)
		result += 1.0 / i;
	return result;
}
//CÂU B
float result_B(int a)
{
	float result = 1;
	for (int i = 2; i <= a; i++)
		result += 1.0 / factorial(a);
	return result;
}
//CÂU C
float result_C(int a)
{
	float result = 1;
	for (int i = 2; i <= a; i++)
		result += pow(-1, i - 1) / factorial(a);
	return result;
}
//CÂU D
long result_D(int a)
{
	return factorial(a);
}
//CÂU E
long result_E(int a)
{
	int result = 1;
	int i = 2;
	if (a % 2)
		i = 1;
	while (i <= a)
	{
		result *= i;
		i += 2;
	}
	return result;
}