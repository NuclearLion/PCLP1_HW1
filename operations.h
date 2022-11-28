#ifndef _OPERATIONS_H_
#define _OPERATIONS_H_

int on_line(int sudoku[400][400], int dim, int lin, int nr);

int on_column(int sudoku[400][400], int dim, int col, int nr);

int in_square(int sudoku[400][400], int n, int dim, int sqr_index, int nr);

int determine_square(int n, int current_i, int current_j);

#endif
