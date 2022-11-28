#ifndef _DISPLAY_H_
#define	_DISPLAY_H_

#include <stdio.h>
#include "operations.h"

void op1(int sudoku[400][400], int dim, int lin);

void op2(int sudoku[400][400], int dim, int col);

void op3(int sudoku[400][400], int n, int car);

void op4(int sudoku[400][400], int n, int dim, int current_i, int current_j);

void op5(int sudoku[400][400], int lin, int col, int c);

int op6(int sudoku[400][400], int dim);

#endif
