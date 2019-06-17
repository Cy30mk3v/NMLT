/*
Họ tên: TODO
MSSV: TODO
*/

#define _CRT_SECURE_NO_WARNINGS // Để dùng được scanf trong VS2017

// KHAI BÁO CÁC THƯ VIỆN
#include <stdio.h>

// KHAI BÁO CÁC HÀM (PROTOTYPE)
float get_param_val(char eq_form[], char param);
int solve_lin_eq(float a, float b, float& x);

// HÀM MAIN
int main()
{
	// Nhập giá trị của các tham số của phương trình
	float a = get_param_val("ax + b = 0", 'a');
	float b = get_param_val("ax + b = 0", 'b');

	// Giải phương trình
	float x;
	int num_sols = solve_lin_eq(a, b, x);

	// Xuất kết quả
	if (num_sols == 0)
		printf("Phuong trinh vo nghiem\n");
	else if (num_sols == 999)
		printf("Phuong trinh co vo so nghiem\n");
	else if (num_sols == 1)
		printf("Phuong trinh co mot nghiem: x = %.3f\n", x);
	else
		printf("So luong nghiem chi co the bang 0, hoac 1, hoac 999 (vo so nghiem)!\n");

	return 0;
}

// ĐỊNH NGHĨA CÁC HÀM ĐÃ KHAI BÁO

/*
Hàm get_param_vals (get parameter values) cho người dùng nhập vào giá trị của một tham
số của phương trình.
ĐẦU VÀO:
	eq_form: chuỗi (gồm nhiều ký tự) cho biết dạng phương trình (vd: "ax + b = 0").
	param: ký tự cho biết tham số cần nhập (vd: là 'a' hay 'b' trong ax + b = 0).
ĐẦU RA: số thực mà người dùng nhập vào ứng với giá trị của một tham số.
*/
float get_param_val(char eq_form[], char param)
{
	float val;
	printf("Nhap vao tham so %c cua phuong trinh %s: ", param, eq_form);
	scanf("%f", &val);
	return val;
}

/*
Hàm solve_lin_eq (solve linear equation) giải phương trình bậc nhất.
ĐẦU VÀO:
	a: số thực cho biết giá trị của a trong ax + b = 0.
	b: số thực cho biết giá trị của b trong ax + b = 0.
	x: số thực dùng để chứa nghiệm của phương trình; nếu phương trình có một nghiệm thì
	biến này sẽ được cập nhật giá trị sau khi hàm này chạy xong.
ĐẦU RA: số nguyên cho biết số lượng nghiệm của phương trình, qui ước: nếu phương trình
có vô số nghiệm thì trả về 999.
*/
int solve_lin_eq(float a, float b, float& x)
{
	if (a == 0 && b == 0)
	{
		return 999;
	}

	if (a == 0)
	{
		return 0;
	}
	x = -b / a;
	return 1;



}