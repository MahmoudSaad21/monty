#include "monty.h"

/**
* rotr - Rotates the last node of the stack to the top.
* @stack: Pointer to a pointer pointing to top node of the stack.
* @ln: Interger representing the line number of of the opcode.
*/
void rotr(stack_t **stack, __attribute__((unused))unsigned int ln)
{
stack_t *tmp;
if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
return;
tmp = *stack;
while (tmp->next != NULL)
tmp = tmp->next;
tmp->next = *stack;
tmp->prev->next = NULL;
tmp->prev = NULL;
(*stack)->prev = tmp;
(*stack) = tmp;
}

/**
* err - Prints appropiate error messages determined by their error code.
* @error_code: The error codes
*/
void err(int error_code, ...)
{
va_list ag;
char *op;
int l_num;
va_start(ag, error_code);
switch (error_code)
{
case 1:
fprintf(stderr, "USAGE: monty file\n");
break;
case 2:
fprintf(stderr, "Error: Can't open file %s\n",
va_arg(ag, char *));
break;
case 3:
l_num = va_arg(ag, int);
op = va_arg(ag, char *);
fprintf(stderr, "L%d: unknown instruction %s\n", l_num, op);
break;
case 4:
fprintf(stderr, "Error: malloc failed\n");
break;
case 5:
fprintf(stderr, "L%d: usage: push integer\n", va_arg(ag, int));
break;
default:
break;
}
free_nodes();
exit(EXIT_FAILURE);
}

/**
* more_err - handles errors.
* @error_code: The error codes
*/
void more_err(int error_code, ...)
{
va_list ag;
char *op;
int l_num;
va_start(ag, error_code);
switch (error_code)
{
case 6:
fprintf(stderr, "L%d: can't pint, stack empty\n",
va_arg(ag, int));
break;
case 7:
fprintf(stderr, "L%d: can't pop an empty stack\n",
va_arg(ag, int));
break;
case 8:
l_num = va_arg(ag, unsigned int);
op = va_arg(ag, char *);
fprintf(stderr, "L%d: can't %s, stack too short\n", l_num, op);
break;
case 9:
fprintf(stderr, "L%d: division by zero\n",
va_arg(ag, unsigned int));
break;
default:
break;
}
free_nodes();
exit(EXIT_FAILURE);
}

/**
* string_err - handles errors.
* @error_code: The error codes are the following:
* (10) ~> The number inside a node is outside ASCII bounds.
* (11) ~> The stack is empty.
*/
void string_err(int error_code, ...)
{
va_list ag;
int l_num;
va_start(ag, error_code);
l_num = va_arg(ag, int);
switch (error_code)
{
case 10:
fprintf(stderr, "L%d: can't pchar, value out of range\n", l_num);
break;
case 11:
fprintf(stderr, "L%d: can't pchar, stack empty\n", l_num);
break;
default:
break;
}
free_nodes();
exit(EXIT_FAILURE);
}