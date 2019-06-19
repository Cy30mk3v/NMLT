/*
HỌ TÊN: VÕ TRẦN CHÍ HƯNG
MSSV: 1753058
*/

#include <stdio.h>

#define N_ROWS 3
#define N_COLS 3
#define GAME_PL1 1
#define GAME_PL2 -1
#define GAME_DRAW 0

void print_board(int a[][N_COLS]);
bool check_full(int a[][N_COLS]);
int check_win(int a[][N_COLS], int x, int y);
void start(int a[][N_COLS]);
int get_playing(int pl);
bool is_xy_empty(int a[][N_COLS], int x, int y);


int main(void)
{
	int x, y, pl;
	pl = 0;
	int playing = 0;
	int A[N_ROWS][N_COLS];
	start(A);
	while (1)
	{
		print_board(A);
		do
		{
			printf("Nhap dong x va cot y: ");
			scanf_s("%i %i", &x, &y);
		} while (x<0 || x>2 || y<0 || y>2 || !is_xy_empty(A, x, y));
		A[y][x] = get_playing(pl);
		playing = check_win(A, x, y);
		if (playing < 0)
			pl = !pl;
		else if (playing == 0) {
			printf("\n0\n");
			return 0;
		}
		else if (playing == 1) {
			printf("\n%d\n", get_playing(pl));
			return 0;
		}
	}
	return 0;

}


/*
Hàm print_board in bàn cờ Tic-Tac-Toe 3x3.
ĐẦU VÀO:
a: mảng số nguyên hai chiều 3x3 cho biết tình trạng của bàn cờ
a[i][j] = 0 nghĩa là ô ở dòng i và cột j chưa được đánh
a[i][j] > 0 nghĩa là ô ở dòng i và cột j đã được đánh "x"
a[i][j] < 0 nghĩa là ô ở dòng i và cột j đã được đánh "o"
ĐẦU RA: không có
*/
void print_board(int a[][N_COLS])
{
	// In chỉ số cột của bàn cờ
	printf("\n   ");
	for (int j = 0; j < N_COLS; j++)
		printf("  %i ", j);
	printf("\n");

	// In đường kẻ ngang của bàn cờ
	printf("   ");
	for (int k = 0; k < N_COLS; k++)
		printf("+---");
	printf("+\n");

	for (int i = 0; i < N_ROWS; i++) // Duyệt dòng
	{
		printf(" %i ", i); // In chỉ số dòng của bàn cờ
		for (int j = 0; j < N_COLS; j++) // Duyệt cột
		{
			if (a[i][j] > 0)
				printf("| x ");
			else if (a[i][j] < 0)
				printf("| o ");
			else
				printf("|   ");
		}
		printf("|\n");

		// In đường kẻ ngang của bàn cờ
		printf("   ");
		for (int k = 0; k < N_COLS; k++)
			printf("+---");
		printf("+\n");
	}
	printf("\n");
}

int check_win(int a[][N_COLS], int x, int y)
{
	if (a[y][0] == a[y][1] && a[y][1] == a[y][2])
		return 1;

	if (a[0][x] == a[1][x] && a[1][x] == a[2][x])
		return 1;

	if ((x == 0 && y == 0) || (x == 1 && y == 1) || (x == 2 && y == 2))
		if (a[0][0] == a[1][1] && a[1][1] == a[2][2])
			return 1;

	if ((x == 2 && y == 0) || (x == 1 && y == 1) || (x == 0 && y == 2))
		if (a[2][0] == a[1][1] && a[1][1] == a[0][2])
			return 1;

	if (check_full(a))
		return 0;

	return -1;
}

bool check_full(int a[][N_COLS])
{
	for (int i = 0; i < N_ROWS; i++)
		for (int j = 0; i < N_COLS; j++)
			if (a[i][j] == 0)
				return false;
	return true;
}

void start(int a[][N_COLS])
{
	for (int i = 0; i < N_ROWS; ++i)
		for (int j = 0; j < N_COLS; ++j)
		{
			a[i][j] = 0;
		}
}



int get_playing(int pl)
{
	if (pl == 0)
		return GAME_PL1;
	return GAME_PL2;
}

bool is_xy_empty(int a[][N_COLS], int x, int y)
{
	return a[y][x] == 0;
}
