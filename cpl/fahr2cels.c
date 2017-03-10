#include <stdio.h>

/* A very simple function. */
hello() {
	printf("This is a useless string!\n\n");
}

/* A first try with floats. */
floattest() {
	float a, b, result;
	a = 4.534523;
	b = 3.334292;
	result = a * b;
	printf("Multiplying %f with %f gives %f \n\n", a, b, result);
}

/* A somewhat more involved function. */
fahr2celsINT() {
	int fahrenheit, celsius, lower, upper, step;
	lower = 0;
	upper = 100;
	step = 1;
	fahrenheit=lower;
	printf("Fahr\tCels\n");
	while (fahrenheit <= upper) {
		celsius = 5 * (fahrenheit-32) / 9;
		printf("%4d\t%4d\n", fahrenheit, celsius);
		fahrenheit = fahrenheit + step;
	}
	printf("\n");
}

/* The same version with floats. */
fahr2celsFLT() {
	float fahrenheit, celsius, lower, upper, step;
	lower = 0.0;
	upper = 100.0;
	step = 1.0;
	fahrenheit=lower;
	printf("Fahr\tCels\n");
	while (fahrenheit <= upper) {
		celsius = (5.0/9.0) * (fahrenheit-32);
		printf("%4.0f\t%6.2f\n", fahrenheit, celsius);
		fahrenheit = fahrenheit + step;
	}
	printf("\n");
}

/* String things you've made together in main. */
main() {
	hello();
	fahr2celsFLT();
	floattest();
}
