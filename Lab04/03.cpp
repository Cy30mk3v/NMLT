/*
Họ tên: TODO
MSSV: TODO
*/

#define _CRT_SECURE_NO_WARNINGS // Để dùng được scanf trong VS2017

// KHAI BÁO CÁC THƯ VIỆN
#include <stdio.h>
#include <math.h>
// TODO: nếu cần thì bạn có thể khai báo thêm các thư viện khác ở đây

// KHAI BÁO CÁC HÀM (PROTOTYPE)
int check_triangle(float a, float b, float c);
// TODO: nếu cần thì bạn có thể khai báo thêm các hàm khác ở đây

// HÀM MAIN
int main()
{
	// Nhập ba số a, b, c
	float a, b, c;
	printf("Nhap ba so a, b, c: ");
	scanf("%f%f%f", &a, &b, &c);

	// Kiểm tra 3 cạnh a, b, c tạo thành tam giác gì
	int result = check_triangle(a, b, c);

	// Xuất kết quả
	if (result == 0)
		printf("Khong tao thanh tam giac\n");
	else if (result == 1)
		printf("Tam giac nhon\n");
	else if (result == 2)
		printf("Tam giac vuong\n");
	else if (result == 3)
		printf("Tam giac tu\n");
	else
		printf("Doc lai phan mo ta ham check_triangle!\n");

	return 0;
}

// ĐỊNH NGHĨA CÁC HÀM

/*
Hàm check_triangle kiểm tra ba cạnh có tạo thành tam giác không, và nếu có thì đó là
tam giác gì (vuông, tù, nhọn).
ĐẦU VÀO:
	a, b, c: 3 số thực ứng với 3 cạnh của tam giác.
ĐẦU RA: số nguyên với qui ước:
	0 - không tạo thành tam giác.
	1 - tam giác nhọn.
	2 - tam giác vuông.
	3 - tam giác tù.
*/
int check_triangle(float a, float b, float c)
{

	float cosA, cosB, cosC, A, B, C;
	cosA = ((b * b + c * c - a * a) / (2 * b * c));
	cosB = ((a * a + c * c - b * b) / (2 * a * c));
	cosC = ((a * a + b * b - c * c) / (2 * a * b));

	if ((a <= 0) || (b <= 0) || (c <= 0) || (a + b <= c) || (a + c <= b) || (b + c <= a))
		return 0;
	else
	{
		if ((a * a + b * b == c * c) || (a * a + c * c == b * b) || (b * b + c * c == a * a))
			return 2;
		if (cosA > 0 && cosB > 0 && cosC > 0)
			return 1;
		else
			return 3;
	}
}

// TODO: nếu cần thì bạn có thể định nghĩa thêm các hàm khác ở đây