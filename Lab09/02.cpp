/*
HỌ TÊN: VÕ TRẦN CHÍ HƯNG
MSSV: 1753058
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <string.h>

void encrypt_by_using_K(char A[100], int k);

int main (void)
{
	char KYTU[100];
	int k;
	printf("Nhap chuoi ky tu can ma hoa: ");
	gets_s(KYTU);
	printf("Nhap khoa K: ");
	scanf_s("%i", &k);
	k = k % 26;
	encrypt_by_using_K(KYTU, k);
	printf("\n");
	printf("Ky tu da ma hoa: ");
	printf("\n");
	puts(KYTU);
}

void encrypt_by_using_K(char A[100],int k)
{
	int new_code, a;
	for (int i=0; A[i]!='\0'; i++)
		{
			if (A[i]>= 'a' && A[i]<='z')
			{
				new_code = A[i] + k;
				if (new_code > 'z')
				{
					a = new_code - 'z' - 1;
					A[i] = 'a' + a;
				}
				else
					if (new_code < 'a')
					{
						a = 'a' - new_code - 1;
						A[i] = 'z' - a;
					}
					else
						A[i] = new_code;
			}
			else 
				if (A[i]>='A'&& A[i]<= 'Z')
				{
					new_code = A[i] + k;
					if (new_code > 'Z')
					{
						a = new_code - 'Z' - 1;
						A[i] = 'A' + a;
					}
					else
						if (new_code < 'A')
						{
							a = 'A' - new_code - 1;
							A[i] = 'Z' - a;
						}
						else
							A[i] = new_code;
				}
		}
}

