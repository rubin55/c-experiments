#include <stdio.h>

/* nicer than #defines */
enum {LOWER = 0, UPPER = 300, STEP = 20};

/* print fahrenheit-celsius table */
main() {
	int fahr;

	for(fahr = LOWER ; fahr <= UPPER ; fahr = fahr + STEP)
		printf("%3d %6.1f\n", fahr, (5.0 / 9.0)*(fahr - 32.0));
}

