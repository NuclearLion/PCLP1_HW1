#include <stdio.h>
#include <stdlib.h>

#define NMAX 1000

int main(void)
{
	int tab[NMAX][NMAX] = {0};
	int border = 0;
	long moves = 0;
	int current_i = 0;
	int current_j = 0;

	scanf("%d", &border);
	for (int i = 0; i < border; ++i)
		for (int j = 0; j < border; ++j)
			scanf("%d", &tab[i][j]);

	while (tab[current_i][current_j]) {
		int current_step = tab[current_i][current_j];

		//total number of moves, regarding the signature
		moves += abs(tab[current_i][current_j]);
		tab[current_i][current_j] = 0;

		if (current_i % 2 == current_j % 2) {//white square
			//left - right on the LINIE
			current_j += current_step;
			while (current_j >= border)
				current_j -= border;
			while (current_j < 0)
				current_j = border + current_j;
		} else {//black square
			//up - down on the COLUMN
			current_i += current_step;
			while (current_i >= border)
				current_i -= border;
			while (current_i < 0)
				current_i = border + current_i;
		}
	}

	//the checkboard is numbered starting from the down left corner...
	int transform_to_checkboard = border - current_i;
	printf("%ld\n", moves);
	printf("%d ", transform_to_checkboard);
	if (current_j < 26) { //showing the letter, case with only one
		printf("%c\n", 'A' + current_j);
	} else { //showing the letter, case with 2 letters
		char first_letter = current_j / 26 + 'A' - 1;
		char second_letter = current_j % 26 + 'A';
		printf("%c%c\n", first_letter, second_letter);
	}
	return 0;
}
