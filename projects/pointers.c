#include <stdio.h>
#include <stdlib.h>

int readInt() {
    int result = 0;

    for (char c = getchar(); c != '\n'; c = getchar()) {
        if (c >= '0' && c <= '9') {
             result = result * 10 + (c - '0');
        }
    }

    return result;
}

int main(void) {
    printf("Enter size of the array: ");
    fflush(stdout);
    const int arraySize = readInt();

    // ta +1 je kvuli posledni byte binarni nule
    char *array = malloc(arraySize + 1);
    array[arraySize] = '\0';

    for (int i = 0; i < arraySize; i++) {
        array[i] = 'A';
    }

    printf("%s\n", array);
    free(array); // cisteni array

    return EXIT_SUCCESS;
}
