#include <stdio.h>
#include <stdlib.h>

#define INPUT "vysky_vahy.txt"
#define OUTPUT "obezita.txt"

typedef struct {
    int height;
    int weight;
} CHARACTER;

CHARACTER* readFile(int *amount) {
    FILE *inputFile = fopen(INPUT, "r");
    if (inputFile == NULL) {
        printf("Error opening file %s\n", INPUT);
        exit(1);
    }

    FILE *outputFile = fopen(OUTPUT, "w");
    if (outputFile == NULL) {
        printf("Error opening file %s\n", OUTPUT);
        exit(1);
    }

    CHARACTER *characters = (CHARACTER *) malloc(sizeof(CHARACTER));
    int index = 0;

    CHARACTER *temp_character = NULL;
    while (fscanf(INPUT, "%d %d", &characters[index].height, &characters[index].weight) == 2) {
        index++;
        temp_character = (CHARACTER *) realloc(characters, (index + 1) * sizeof(CHARACTER));

        if (temp_character != NULL) {
            characters = temp_character;
        } else {
            free(characters);
            puts("Error (re)allocating memory");
            exit(1);
        }
    }

    if (fclose(inputFile) != 0) {
        printf("Error closing file %s\n", INPUT);
        exit(1);
    }

    if (fclose(outputFile) != 0) {
        printf("Error closing file %s\n", OUTPUT);
        exit(1);
    }

    *amount = index;
    return characters;
}

int main(void) {
    int amount;
    CHARACTER *characters = readFile(&amount);

    return EXIT_SUCCESS;
}
