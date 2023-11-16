#include "main.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        fprintf(stderr, "Error: Could not open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    char opcode[100];
    int value;
    int line_number = 1;

    while (fscanf(file, "%s", opcode) != EOF) {
        if (strcmp(opcode, "push") == 0) {
            if (fscanf(file, "%d", &value) != 1) {
                fprintf(stderr, "L%d: usage: push integer\n", line_number);
                exit(EXIT_FAILURE);
            }
            push(value);
        } else if (strcmp(opcode, "pall") == 0) {
            pall();
        } else {
            fprintf(stderr, "L%d: unknown opcode %s\n", line_number, opcode);
            exit(EXIT_FAILURE);
        }

        line_number++;
    }

    fclose(file);

    return EXIT_SUCCESS;
}