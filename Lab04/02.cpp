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
float get_param_val(char eq_form[], char param);
int solve_quad_eq(float a, float b, float c, float& x1, float& x2);
// TODO: nếu cần thì bạn có thể khai báo thêm các hàm khác ở đây

// HÀM MAIN
int main()
{
	// Nhập giá trị của các tham số của phương trình
	char eq_form[] = "ax^2 + bx + c = 0";
	float a = get_param_val(eq_form, 'a');
	float b = get_param_val(eq_form, 'b');
	float c = get_param_val(eq_form, 'c');

	// Giải phương trình
	float x1, x2;
	int num_sols = solve_quad_eq(a, b, c, x1, x2);

	// Xuất kết quả
	if (num_sols == 0)
		printf("Phuong trinh vo nghiem\n");
	else if (num_sols == 999)
		printf("Phuong trinh co vo so nghiem\n");
	else if (num_sols == 1)
		printf("Phuong trinh co mot nghiem: x = %.3f\n", x1);
	else if (num_sols == 2)
		printf("Phuong trinh co hai nghiem: x1 = %.3f va x2 = %.3f\n", x1, x2);
	else
		printf("So luong nghiem chi co the bang 0, hoac 1, hoac 2, hoac 999 (vo so nghiem)!\n");

	return 0;
}

// ĐỊNH NGHĨA CÁC HÀM

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
Hàm solve_quad_eq (solve quadratic equation) giải phương trình bậc hai.
ĐẦU VÀO:
	a: số thực cho biết giá trị của a trong ax^2 + bx + c = 0.
	b: số thực cho biết giá trị của b trong ax^2 + bx + c = 0.
	c: số thực cho biết giá trị của c trong ax^2 + bx + c = 0.
	x1, x2: hai số thực dùng để chứa nghiệm của phương trình; nếu phương trình có một
	nghiệm thì x1 sẽ được cập nhật giá trị sau khi hàm này chạy xong; nếu phương trình
	có hai nghiệm thì x1 và x2 sẽ được cập nhật giá trị sau khi hàm này chạy xong, qui
	ước: x1 < x2.
ĐẦU RA: số nguyên cho biết số lượng nghiệm của phương trình, qui ước: nếu phương trình
có vô số nghiệm thì trả về 999.
*/
int solve_quad_eq(float a, float b, float c, float& x1, float& x2)
{

	float delta = (b * b) - (4 * a * c);
	if (delta < 0)
	{
		return 0;
	}
	if (delta == 0)
	{
		x1 = x2 = -b / (2 * a);
		return 1;
	}
	if (delta > 0)
	{
		x1 = (-b - sqrt(delta)) / (2 * a);
		x2 = (-b + sqrt(delta)) / (2 * a);
		return 2;
	}


}

// TODO: nếu cần thì bạn có thể định nghĩa thêm các hàm khác ở đây