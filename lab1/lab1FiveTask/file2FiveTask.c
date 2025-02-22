#include <stdio.h>

static int counter = 0;

void incrementCounter() {
    counter++;
    printf("Счетчик: %d\n", counter);
}