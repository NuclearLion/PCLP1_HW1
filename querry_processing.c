#include "querry_processing.h"
#include <stdio.h>

//interogate the querry
void interog(int k, int freq[], int nr_of_letters)
{
	typedef struct {
		int freq;
		char letter;
	} sorting_vector;
	sorting_vector vect[26];

	for (int i = 0; i < nr_of_letters; ++i) {
		vect[i].freq = freq[i];
		vect[i].letter = (char)('a' + i);
	}

	for (int i = 0; i < nr_of_letters - 1; ++i)
		for (int j = i + 1; j < nr_of_letters; ++j)
			if (vect[i].freq < vect[j].freq) {
				sorting_vector aux = vect[i];
				vect[i] = vect[j];
				vect[j] = aux;
			} else if (vect[i].freq == vect[j].freq) {
				if (vect[i].letter > vect[j].letter) {
					sorting_vector aux = vect[i];
					vect[i] = vect[j];
					vect[j] = aux;
				}
			}

	for (int i = 0; i < k - 1; ++i)
		printf("%c ", vect[i].letter);
	printf("%c\n", vect[k - 1].letter);
}

//find the cmmdc of 2 numbers
int cmmdc(int a, int b)
{
	while (b) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

//check if alert is needed and display it
void alert(char unic, int curr_in, int *last_alert, int *letter_fr, int ltr)
{
	if (unic == 0 && curr_in >= 5 && *last_alert >= 5) {
		for (int i = 0; i < ltr; ++i) {
			float fifty = curr_in / 2.0;
			if (letter_fr[i] >= fifty) {
				//a fraction is reductible by the cmmdc of the 2 numbers
				int local_cmmdc = cmmdc(letter_fr[i], curr_in);
				int red_letter = letter_fr[i] / local_cmmdc;
				int red_cnt = curr_in / local_cmmdc;
				char cur_letter = i + 'a';
				printf("%c %d/%d\n", cur_letter, red_letter, red_cnt);
				*last_alert = 0;
			}
		}
	}
}
