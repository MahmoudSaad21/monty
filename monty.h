#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

void open_F(char *file_name);
int Analysis_line(char *buffer, int line_number, int format);
void read_F(FILE *);
int len_chars(FILE *);
void find(char *, char *, int, int);
stack_t *create(int n);
void free_nodes(void);
void print_all(stack_t **, unsigned int);
void push_to_stack(stack_t **, unsigned int);
void push_to_queue(stack_t **, unsigned int);
void call(op_func, char *, char *, int, int);
void print_top(stack_t **, unsigned int);
void pop_to_stack(stack_t **, unsigned int);
void no_op(stack_t **, unsigned int);
void swap_n(stack_t **, unsigned int);
void add_n(stack_t **, unsigned int);
void sub_n(stack_t **, unsigned int);
void div_n(stack_t **, unsigned int);
void mul_n(stack_t **, unsigned int);
void mod_n(stack_t **, unsigned int);
void print_char(stack_t **, unsigned int);
void print_str(stack_t **, unsigned int);
void rotl(stack_t **, unsigned int);
void err(int error_code, ...);
void more_err(int error_code, ...);
void string_err(int error_code, ...);
void rotr(stack_t **, unsigned int);

#endif
