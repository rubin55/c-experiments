#include <stdio.h>

/* Count lines in input, 1st version. */
main() {
    long c, nl;

    nl=0;

    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            ++nl;
        }
    }

    printf("%ld\n", nl);
}
