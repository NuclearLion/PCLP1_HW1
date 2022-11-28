#include <stdio.h>
#include "display.h"

int main(void)
{
	int n = 0, m = 0;
	int sudoku[400][400];
	scanf("%d%d", &n, &m);
	int dim_mat = n * n;
	for (int i = 0; i < dim_mat; ++i)
		for (int j = 0; j < dim_mat; ++j)
			scanf("%d", &sudoku[i][j]);

	for (int i = 0; i < m; ++i) {
		int nr_op = 0;
		int x = 0;
		int y = 0;
		int z = 0;
		int c = 0;
		scanf("%d", &nr_op);

		switch (nr_op) {
		case 1:
			scanf("%d", &x);
			op1(sudoku, dim_mat, x);
			break;
		case 2:
			scanf("%d", &y);
			op2(sudoku, dim_mat, y);
			break;
		case 3:
			scanf("%d", &z);
			op3(sudoku, n, z);
			break;
		case 4:
			scanf("%d%d", &x, &y);
			op4(sudoku, n, dim_mat, x, y);
			break;
		case 5:
			scanf("%d%d%d", &x, &y, &c);
			op5(sudoku, x, y, c);
			break;
		case 6:
			printf("%d\n", op6(sudoku, dim_mat));
			break;
		default:
			perror("something went really bad :(\n");
			break;
		}
	}
	return 0;
}
