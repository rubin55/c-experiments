#include <stdio.h>

cel2fahrs() {
	float celsius;
	printf("%6s\t%6s\n", "Celsius", "Fahrenheit");
	for (celsius=0.0; celsius<200; celsius+=20)
		printf("%6.2f\t%6.2f\n", celsius, celsius/5.0*9.0+32);
}

cel2fahrADVANCED() {
        float celsius, fahrenheit, lower, upper, step;
        lower = 0.0;
        upper = 100.0;
        step = 1.0;
        fahrenheit=lower;
        celsius=lower;
        printf("Cels\tFahr\n");
        while (celsius <= upper) {
                fahrenheit = (9.0/5.0) * celsius + 32;
                printf("%4.0f\t%6.2f\n", celsius, fahrenheit);
                celsius = celsius + step;
        }
        printf("\n");
}

main() {
	cel2fahrs();
}
