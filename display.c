#include "display.h"

//checks every number if it's on the line
void op1(int sudoku[400][400], int dim, int lin)
{
	lin--; //real index
	for (int nr = 1; nr <= dim; ++nr)
		printf("%d ", !on_line(sudoku, dim, lin, nr));
	printf("\n");
}

//checks every number if it's on the column
void op2(int sudoku[400][400], int dim, int col)
{
	col--; //real index
	for (int nr = 1; nr <= dim; ++nr)
		printf("%d ", !on_column(sudoku, dim, col, nr));
	printf("\n");
}

//checks if every number is in the square
void op3(int sudoku[400][400], int n, int sqr)
{
	sqr--; //real index of square
	int dim = n * n;
	for (int nr = 1; nr <= dim; ++nr)
		printf("%d ", !in_square(sudoku, n, dim, sqr, nr));
	printf("\n");
}

//checks which numbers can be placed at given coords
void op4(int sudoku[400][400], int n, int dim, int current_i, int current_j)
{
	current_i--;//real index from 0
	current_j--;//real index from 0

	if (sudoku[current_i][current_j] != 0) {
		for (int i = 1; i <= dim; ++i)
			printf("0 ");
		printf("\n");
	} else {
		int current_square = determine_square(n, current_i, current_j);
		for (int nr = 1; nr <= dim; ++nr)
			if (!on_line(sudoku, dim, current_i, nr) &&
				!on_column(sudoku, dim, current_j, nr) &&
				!in_square(sudoku, n, dim, current_square, nr))
				printf("1 ");
			else
				printf("0 ");
		printf("\n");
	}
}

//places given number at given coords
void op5(int sudoku[400][400], int lin, int col, int c)
{
	lin--;//real index
	col--;//real index
	if (sudoku[lin][col] == 0)
		sudoku[lin][col] = c;
}

//checks sudoku's state (0, 1, 2)
int op6(int sudoku[400][400], int dim)
{
	int is_zero = 0;
	for (int fixed_lin = 0; fixed_lin < dim; ++fixed_lin) {
		int fr_col[401] = {0};
		for (int j = 0; j < dim; ++j)
			if (sudoku[fixed_lin][j] != 0) {
				++fr_col[sudoku[fixed_lin][j]];
				if (fr_col[sudoku[fixed_lin][j]] > 1)
					return 1;
			} else {
				is_zero = 1;
			}
	}

	for (int fixed_col = 0; fixed_col < dim; ++fixed_col) {
		int fr_lin[401] = {0};
		for (int i = 0; i < dim; ++i)
			if (sudoku[i][fixed_col] != 0) {
				++fr_lin[sudoku[i][fixed_col]];
				if (fr_lin[sudoku[i][fixed_col]] > 1)
					return 1;
			} else {
				is_zero = 1;
			}
	}
	if (is_zero)
		return 0;
	return 2;
}
