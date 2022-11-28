#include "operations.h"

//checks if given number is on the line
int on_line(int sudoku[400][400], int dim, int lin, int nr)
{
	int lin_ap = 0;
	for (int j = 0; j < dim; ++j)
		if (sudoku[lin][j] == nr)
			lin_ap++;
	return lin_ap;
}

//checks if given number is on the column
int on_column(int sudoku[400][400], int dim, int col, int nr)
{
	int col_ap = 0;
	for (int i = 0; i < dim; ++i)
		if (sudoku[i][col] == nr)
			col_ap++;
	return col_ap;
}

//checks if given number is in square
int in_square(int sudoku[400][400], int n, int dim, int sqr_index, int nr)
{
	//start of square
	int current_index = 0;
	int sqr_start_i = 0;
	int sqr_start_j = 0;

	while (current_index < sqr_index) {
		if (sqr_start_j + n < dim) {
			sqr_start_j += n;
		} else {
			sqr_start_i += n;
			sqr_start_j = 0;
		}
		current_index++;
	}
	//is in square?
	int sqr_ap = 0;
	for (int i = sqr_start_i; i < sqr_start_i + n; ++i)
		for (int j = sqr_start_j; j < sqr_start_j + n; ++j)
			if (sudoku[i][j] == nr)
				sqr_ap++;
	return sqr_ap;
}

//determines in which square are the given coords
int determine_square(int n, int current_i, int current_j)
{
	int squares_on_top = 0;
	int squares_on_left = 0;

	while (current_i - n >= 0) {
		squares_on_top++;
		current_i -= n;
	}
	while (current_j - n >= 0) {
		squares_on_left++;
		current_j -= n;
	}
	int square_index = squares_on_top * n + squares_on_left;
	return square_index;
}
