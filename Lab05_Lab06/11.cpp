/*
HỌ TÊN: VÕ TRẦN CHÍ HƯNG
MSSV: 1753058
*/

#define _CRT_SECURE_NO_WARNINGS // Để dùng được scanf trong VS2017

// KHAI BÁO CÁC THƯ VIỆN
#include <stdio.h>
#include <math.h>
// TODO: nếu cần thì bạn có thể khai báo thêm các thư viện khác ở đây
#define epsilon 0.0000001
// KHAI BÁO CÁC HÀM (PROTOTYPE)
double get_param_val(char eq_form[], char param);
int solve_cub_eq(double a, double b, double c, double d, double &x1, double &x2, double &x3);
// TODO: nếu cần thì bạn có thể khai báo thêm các hàm khác ở đây-
int solve_quad_eq(double a, double b, double c, double &x1, double &x2);
double search_sol(double a, double b, double c, double d, double l, double r);
void swap(double &a, double &b);
double put_eq(double a, double b, double c, double d, double x);

// HÀM MAIN
int main()
{
	// Nhập giá trị của các tham số của phương trình
	double a, b, c, d;
	char eq_form[] = "ax^3 + bx^2 + cx + d = 0";
	a = get_param_val(eq_form, 'a');
	b = get_param_val(eq_form, 'b');
	c = get_param_val(eq_form, 'c');
	d = get_param_val(eq_form, 'd');

	// Giải phương trình
	double x1, x2, x3;
	int num_sols = solve_cub_eq(a, b, c, d, x1, x2, x3);

	// Xuất kết quả
	if (num_sols == 0)
		printf("\nPhuong trinh vo nghiem\n");
	else if (num_sols == 999)
		printf("\nPhuong trinh co vo so nghiem\n");
	else if (num_sols == 1)
		printf("\nPhuong trinh co mot nghiem:\n%lf\n", x1);
	else if (num_sols == 2)
		printf("\nPhuong trinh co hai nghiem:\n%lf %lf\n", x1, x2);
	else if (num_sols == 3)
		printf("\nPhuong trinh co ba nghiem:\n%lf %lf %lf\n", x1, x2, x3);
	else
		printf("So luong nghiem chi co the bang 0, hoac 1, hoac 2, hoac 3, hoac 999 (vo so nghiem)!\n");
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
double get_param_val(char eq_form[], char param)
{
	double val;
	printf("Nhap vao tham so %c cua phuong trinh %s: ", param, eq_form);
	scanf("%lf", &val);
	return val;
}

/*
Hàm solve_cub_eq (solve cubic equation) giải phương trình bậc ba.
ĐẦU VÀO:
a: số thực cho biết giá trị của a trong ax^3 + bx^2 + cx + d = 0.
b: số thực cho biết giá trị của b trong ax^3 + bx^2 + cx + d = 0.
c: số thực cho biết giá trị của c trong ax^3 + bx^2 + cx + d = 0.
d: số thực cho biết giá trị của d trong ax^3 + bx^2 + cx + d = 0.
x1, x2, x3: ba số thực dùng để chứa nghiệm của phương trình; nếu phương trình có một
nghiệm thì x1 sẽ được cập nhật giá trị sau khi hàm này chạy xong; nếu phương trình
có hai nghiệm thì x1 và x2 sẽ được cập nhật giá trị sau khi hàm này chạy xong, qui
ước: x1 < x2; nếu phương trình có ba nghiệm thì x1, x2 và x3 sẽ được cập nhật giá trị
sau khi hàm này chạy xong, qui ước: x1 < x2 < x3.
ĐẦU RA: số nguyên cho biết số lượng nghiệm của phương trình, qui ước: nếu phương trình
có vô số nghiệm thì trả về 999.
*/
int solve_cub_eq(double a, double b, double c, double d, double &x1, double &x2, double &x3)
{
	if (a == 0)
		return solve_quad_eq(b, c, d, x1, x2);

	double 	d1, d2;
	int n = solve_quad_eq(3 * a, 2 * b, c, d1, d2);
	if (n == -1 || n == 1) {
		x1 = search_sol(a, b, c, d, -999.0, 999.0);
		printf("FUCK!\n");
		return 1;
	}
	else {
		double fd1 = put_eq(a, b, c, d, d1);
		double fd2 = put_eq(a, b, c, d, d2);

		if (fd1 * fd2 < 0) {
			x1 = search_sol(a, b, c, d, -999.0, d1);
			x2 = search_sol(a, b, c, d, d1, d2);
			x3 = search_sol(a, b, c, d, d2, 999.0);
			return 3;

		}
		else if (fd1 * fd2 == 0) {
			if (fd1 == 0) {
				x2 = d2;
				x1 = search_sol(a, b, c, d, d2, d1 - d2);
			}
			else if (fd2 == 0) {
				x2 = d2;
				x1 = search_sol(a, b, c, d, d1, d2 - d1);
			}
			if (x1 > x2)
				swap(x1, x2);
			return 2;

		}
		else {
			if (fd1 * put_eq(a, b, c, d, -999.0) < 0) {
				x1 = search_sol(a, b, c, d, -999.0, d1);
			}
			else if (fd2 * put_eq(a, b, c, d, 999.0) < 0) {
				x1 = search_sol(a, b, c, d, d2, 999.0);
			}
			return 1;
		}
	}
	return 0;
}

// TODO

int solve_quad_eq(double a, double b, double c, double &x1, double &x2)
{
	float delta = (b * b) - (4 * a * c);
	if (a == 0 && b == 0)
	{
		if (c == 0)
			return 999;
		else return 0;
	}
	if (a == 0)
	{
		x1 = -c / b;
		return 1;
	}
	if (delta == 0) {
		x1 = -b / (2 * a);
		return 1;
	}

	if (delta > 0) {
		x1 = (-b - sqrt(delta)) / (2 * a);
		x2 = (-b + sqrt(delta)) / (2 * a);
		if (x1 > x2)
			swap(x1, x2);
		return 2;
	}
	return 0;
}

double search_sol(double a, double b, double c, double d, double l, double r)
{
	double m;
	double fm, fr;
	while (r - l > epsilon)
	{
		m = (l + r) / 2;
		fm = put_eq(a, b, c, d, m);
		fr = put_eq(a, b, c, d, r);

		if (fm * fr > 0)
			r = m;
		else if (fm * fr < 0)
			l = m;
		else
			return m;
	}
	return (l + r) / 2;
}

double put_eq(double a, double b, double c, double d, double x)
{
	return a*x*x*x + b*x*x + c*x + d;
}

void swap(double &a, double &b)
{
	int c = a;
	a = b;
	b = c;
}
// TODO: nếu cần thì bạn có thể định nghĩa thêm các hàm khác ở đây