/*
HỌ TÊN: VÕ TRẦN CHÍ HUNG
MSSV: 1753058
*/

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <conio.h>
void split_covert(char *s);

int main()
{
	char HOTEN[50];
	char *s;
	printf("Nhap ho va ten: ");
	gets_s(HOTEN);
	s = strupr(HOTEN);
	printf("\n");
	split_covert(s);
	printf("\n");
	getchar();
	return 0;
}

void split_covert(char *s)
{
	int i, j, a;
	j = 0;
	a = 0;
	if (s[0] != ' ')
		printf("%c", s[0]);
	for (i = 1; i < (strlen(s)); i++)
	{
		if (s[i - 1] == ' ' && s[i] != ' ')
			printf("%c", s[i]);
	}
}
