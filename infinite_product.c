#include <stdio.h>
#include <math.h>
#include <limits.h>
#include "base_conversion.h"

int main(void)
{
	int n = 0;
	unsigned long prod_scal = 0;
	long max1_a = -1;
	long max1_b = -1;
	long max2_a = -1;
	long max2_b = -1;
	double sum_n_a = 0.0;
	double sum_n_b = 0.0;

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		long base8_a, base8_b;
		scanf("%lu%lu", &base8_a, &base8_b);

		//transform to 10th base from 8th
		long a = base_8_10(base8_a);
		long b = base_8_10(base8_b);

		prod_scal += a * b;

		//in case a new number is greater than both the max and 2nd max
		if (a > max1_a) {
			max2_a = max1_a;
			max1_a = a;
		} else if (a < max1_a && a > max2_a) {
			//in case new number is between the maxs
			max2_a = a;
		}
		//same thing but for b
		if (b > max1_b) {
			max2_b = max1_b;
			max1_b = b;
		} else if (b < max1_b && b > max2_b) {
			max2_b = b;
		}
		sum_n_a += a * a;
		sum_n_b += b * b;
	}
	double n_a = sqrt(sum_n_a);
	double n_b = sqrt(sum_n_b);

	printf("%lu\n", prod_scal);
	printf("%ld %ld\n", max2_a, max2_b);

	if (sum_n_a < 0 && max1_b == 1)
		printf("%0.7f %0.7f\n", (double)prod_scal, n_b);
	else if (sum_n_b < 0 && max1_a == 1)
		printf("%0.7f %0.7f\n", n_a, (double)prod_scal);
	else
		printf("%0.7f %0.7f\n", n_a, n_b);
	return 0;
}
