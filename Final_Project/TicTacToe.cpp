/*
HỌ TÊN: VÕ TRẦN CHÍ HƯNG
MSSV: 1753058
*/

#include <stdio.h>

#define N_ROWS 3
#define N_COLS 3
#define HUMAN_PL  -1
#define COMPUTER_PL 1

typedef struct Move {
	int x, y;
} Move;

int  evaluate(int a[][N_COLS]);
int  minmax(int a[][N_COLS], int player);
void computer_move(int a[][N_COLS]);
void player_move(int a[][N_COLS]);
int  start_game(int a[][N_COLS]);
bool check_legal(int a[][N_COLS], Move move);
bool check_full(int a[][N_COLS]);
void set_move(int a[][N_COLS], Move move, int val);
void print_board(int a[][N_COLS]);

int main(void)
{
	int table[N_ROWS][N_COLS] =
	{
		{ 0, 0, 0 },
		{ 0, 0, 0 },
		{ 0, 0, 0 } };

	printf("\n%d\n", start_game(table));
}

int evaluate(int a[][N_COLS])
{
	for (int i = 0; i < 3; ++i)
	{
		if (a[i][0] == a[i][1] && a[i][1] == a[i][2])
			return a[i][0];
		if (a[0][i] == a[1][i] && a[1][i] == a[2][i])
			return a[0][i];
	}
	if (a[0][0] == a[1][1] && a[1][1] == a[2][2])
		return a[1][1];
	if (a[2][0] == a[1][1] && a[1][1] == a[0][2])
		return a[1][1];
	return 0;
}

int minmax(int a[][N_COLS], int player)
{
	int winner = evaluate(a);
	if (winner != 0)
	{
		return winner * player;
	}
	if (check_full(a))
		return 0;
	Move move = { -1, -1 };
	int maxval = -2;
	int temp = 0;
	for (int i = 0; i < N_ROWS; ++i) {
		for (int j = 0; j < N_COLS; ++j) {
			move.x = j;
			move.y = i;
			if (check_legal(a, move)) {

				set_move(a, move, player);
				temp = -minmax(a, player * -1);
				set_move(a, move, 0);

				if (temp > maxval)
				{
					maxval = temp;
				}
			}
		}
	}
	return maxval;
}

void computer_move(int a[][N_COLS])
{
	Move move = { -1, -1 };
	Move tempMove = { -1, -1 };

	int maxval = -2;
	int temp = 0;
	for (int i = 0; i < N_ROWS; ++i) {
		for (int j = 0; j < N_COLS; ++j) {
			tempMove.x = j;
			tempMove.y = i;

			if (check_legal(a, tempMove))
			{
				set_move(a, tempMove, COMPUTER_PL);
				temp = -minmax(a, HUMAN_PL);
				set_move(a, tempMove, 0);
				if (temp > maxval) {
					maxval = temp;
					move = tempMove;
				}
			}
		}
	}
	set_move(a, move, COMPUTER_PL);
	print_board(a);
}

int start_game(int table[][N_COLS])
{
	int val = 0;
	while (1)
	{
		computer_move(table);
		val = evaluate(table);
		if (val != 0) {
			return val;
		}
		else if (check_full(table))
		{
			return 0;
		}

		player_move(table);
		val = evaluate(table);
		if (val != 0)
		{
			return val;
		}
		else if (check_full(table))
		{
			return 0;
		}

	}
	return 0;
}

void player_move(int a[][N_COLS])
{
	Move move = { -1, -1 };
	do {
		printf("(Nhap x, y): ");
		scanf_s("%d %d", &move.x, &move.y);
	} while (!check_legal(a, move));
	set_move(a, move, HUMAN_PL);

	print_board(a);
}

void set_move(int a[][N_COLS], Move move, int val)
{
	a[move.y][move.x] = val;
}


bool check_legal(int a[][N_COLS], Move move)
{
	if (move.x < 0 || move.x >= N_COLS)
		return false;
	if (move.y < 0 || move.y >= N_ROWS)
		return false;
	return a[move.y][move.x] == 0;
}

bool check_full(int a[][N_COLS])
{
	for (int i = 0; i < N_ROWS; ++i)
		for (int j = 0; j < N_COLS; ++j)
			if (a[i][j] == 0)
				return false;
	return true;
}




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
				printf("| o ");
			else if (a[i][j] < 0)
				printf("| x ");
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