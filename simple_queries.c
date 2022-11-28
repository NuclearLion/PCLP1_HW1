#include <stdio.h>
#include "querry_processing.h"

#define LETTERS 26

int main(void)
{
	int letter_fr[LETTERS] = {0};
	char c = 0, c_ant = 0;
	char unic = 1;
	int current_index = 0;
	int last_alert = 0;
	int cnt_letters_all = 0;

	scanf("%c", &c);
	while ((c >= 'a' && c <= 'z') || c == 'E' || c == 'T' || c == 'Q') {
		if (c >= 'a' && c <= 'z') {
			cnt_letters_all++;
			letter_fr[(int)(c - 'a')]++;
			last_alert++;
			current_index++;
			if (c_ant != 0 && c != c_ant)
				unic = 0;
			alert(unic, current_index, &last_alert, letter_fr, LETTERS);
		} else {
			char l = 0;
			int k = 0;
			switch (c) {
			case 'Q':
				getchar();
				scanf("%c", &l);
				printf("%c %d\n", l, letter_fr[(int)(l - 'a')]);
				break;
			case 'E':
				getchar();
				scanf("%c", &l);
				int index = l - 'a';
				current_index -= letter_fr[index];
				letter_fr[index] = 0;
				break;
			case 'T':
				getchar();
				scanf("%d", &k);
				interog(k, letter_fr, LETTERS);
				break;
			default:
				perror("Something went really bad :(\n");
				break;
			}
		}
		if (c >= 'a' && c <= 'z')
			c_ant = c;
		getchar();
		scanf("%c", &c);
	}
	return 0;
}
