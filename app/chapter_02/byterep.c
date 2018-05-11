#include <stdio.h>
#include <stdlib.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t length) {
    int i;

    for (i = 0; i < length; i++) {
        printf(" %.2x", start[i]);
    }
    printf("\n");
}

void show_int(int x) {
    show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x) {
    show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x) {
    show_bytes((byte_pointer) &x, sizeof(void *));
}

int main(int argc, char **argv) {

    if (argc <= 1) {
        printf("Please specify a number. For example:\n");
        printf("%s 12345", argv[0]);
        return 1;
    }

    int i = atoi(argv[1]);
    float f = (float) i;

    int *p = &i;

    show_int(i);
    show_float(f);
    show_pointer(p);

    return 0;
};
