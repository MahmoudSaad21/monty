#include <stdio.h>
#include <stdlib.h>
#include "main.h"

#define STACK_SIZE 1000

int stack[STACK_SIZE];
int top = -1;  // Initialize the stack pointer

void push(int value) {
    if (top == STACK_SIZE - 1) {
        fprintf(stderr, "Error: Stack overflow\n");
        exit(EXIT_FAILURE);
    }

    stack[++top] = value;
}

void pall() {
    int i;
    for (i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}
