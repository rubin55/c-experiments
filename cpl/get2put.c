#include <stdio.h>

main() {
	printf("Dit is EOF: %i \n", EOF);
	printf("Typ maar iets, dan herhaalt ie het!\n");
	int c;
	c = getchar();
	while(c != EOF) {
		putchar(c);
		c = getchar();
	}
}
