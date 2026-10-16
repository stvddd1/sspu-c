#include <stdio.h>
#include <stdlib.h>

int main (void) {
    int input;
    char *symbols = NULL;
    char *temp_symbols = NULL;
    int count = 0;

    printf("Enter symbols:\n");
    while ((input = getchar()) != '\n') {
        temp_symbols = (char*) realloc(symbols, (count+1) * sizeof(char));

        if (temp_symbols != NULL) {
            symbols = temp_symbols;
            symbols[count] = (char) input;
            count++;
        } else {
            free(symbols);
            puts("Error (re)allocating memory");
            exit(1);
        }
    }

    puts("Symbols that were written:");
    for (int i = 0; i < count; i++) {
        printf("%c", symbols[i]);
    }
    puts("");

    free(symbols);
    symbols = NULL;

    return EXIT_SUCCESS;
}
