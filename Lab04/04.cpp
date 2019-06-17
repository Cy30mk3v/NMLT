/*
HỌ TÊN : VÕ TRẦN CHÍ HƯNG
MSSV:1753058
*/

//KHAI BÁO THƯ VIỆN
#include <stdio.h>

//KHAI BÁO CÁC HÀM
int		check_input_data(int);

int		read();

void	print(int);

int main()
{
	//Nhập giá trị cần đọc
	print(read());
}

int		read() {
	int result;
	printf("Nhap n (0 <= n <= 999): ");
	scanf_s(" %d", &result);
	while (!check_input_data(result))
	{
		printf("Nhap sai, moi nhap lai n (0 <= n <= 999): ");
		scanf_s(" %d", &result);
	}
	return result;
}

void	print(int a) {
	int b = a / 100; 
	int c = (a - (b * 100)) / 10;
	int d = a - ((b * 100) + (c * 10));

	switch (b)
	{
	case 0: printf(" ");
		break;
	case 1: printf("mot tram ");
		break;
	case 2: printf("hai tram ");
		break;
	case 3: printf("ba tram ");
		break;
	case 4: printf("bon tram ");
		break;
	case 5: printf("nam tram ");
		break;
	case 6: printf("sau tram ");
		break;
	case 7: printf("bay tram ");
		break;
	case 8: printf("tam tram ");
		break;
	case 9: printf("chin tram ");
		break;
	}
	if (b == 0, c == 0)
		printf(" ");
	else switch (c)
	{
	case 0: printf("le ");
		break;
	case 1: printf("muoi ");
		break;
	case 2: printf("hai muoi ");
		break;
	case 3: printf("ba muoi ");
		break;
	case 4: printf("bon muoi ");
		break;
	case 5: printf("nam muoi ");
		break;
	case 6: printf("sau muoi ");
		break;
	case 7: printf("bay muoi ");
		break;
	case 8: printf("tam muoi ");
		break;
	case 9: printf("chin muoi ");
		break;
	}
	{if (b == 0 && c ==0 && d == 5)
		printf("nam");
	if (b == 0 && c == 0 && d == 0)
		printf("khong");
	else
		switch (d)
		{
		case 0: printf(" ");
			break;
		case 1: printf("mot");
			break;
		case 2: printf("hai");
			break;
		case 3: printf("ba");
			break;
		case 4: printf("bon");
			break;
		case 5: printf("lam");
			break;
		case 6: printf("sau");
			break;
		case 7: printf("bay");
			break;
		case 8: printf("tam");
			break;
		case 9: printf("chin");
			break;
		}}
}

int		check_input_data(int result)
{
	return 0 <= result && result <= 999;
}