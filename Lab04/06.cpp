/*
HỌ TÊN: VÕ TRẦN CHÍ HƯNG
MSSV: 1753058*/

//KHAI BÁO THƯ VIỆN
#include <stdio.h>

//KHAI BÁO CÁC HÀM
int check_day_month_input(int day, int month, int year);

int main()
{
	int day, month, year, weekdays;
	printf("Nhap ngay, thang, nam: ");
	scanf_s(" %i %i %i", &day, &month, &year);
	while (check_day_month_input(day, month, year) == 0)
	{
		printf("Nhap lai ngay, thang, nam: ");
		scanf_s("%i %i %i", &day, &month, &year);
	}
	if (month < 3) {
		month = month + 12;
		weekdays = (day + 2 * month + (3 * (month + 1)) / 5 + (year-1) + ((year-1) / 4)) % 7;
	}
	else
		weekdays = (day + 2 * month + (3 * (month + 1)) / 5 + year + (year / 4)) % 7;
	switch (weekdays)
	{
	case 0: printf("CN");
		break;
	case 1: printf("2");
		break;
	case 2: printf("3");
		break;
	case 3: printf("4");
		break;
	case 4: printf("5");
		break;
	case 5: printf("6");
		break;
	case 6: printf("7");
		break;
	}
	printf("\n");

}
/*HÀM check_day_month_input kiểm tra đầu vào
ĐẦU VÀO:
day:   số nguyên biểu trưng giá trị ngày nhập vào
month: số nguyên biểu trưng giá trị tháng nhập vào
year:  số nguyên biểu trưng giá trị năm nhập vào 
ĐẦU RA: Cho biết ngày tháng nhập vào có hợp lệ hay không.
QUY ƯỚC: Nếu nhập đúng thì trả về 1, nếu nhập sai thì trả ra giá trị 0

*/

int check_day_month_input(int day, int month, int year)
{
	if (year > 3000 || year <= 0)
		return 0;
	if (day <= 0 || day > 31)
		return 0;
	if (month <= 0 || month > 12)
		return 0;
	if ((month == 2) && (day > 28))
	{	
		if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
			return 1;
		else return 0;
	}
		
	else
	{
		if ((month == 4 || month == 6 || month == 9 || month == 11) && (day > 30))
			return 0;
	}
	return 1;
}