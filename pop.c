#include "monty.h"

/**
 * pop - removes the top element of the stack
 *
 * @stack: pointer to the stack
 * @line_number: line number of the opcode
 */

void pop(stack_t **stack, unsigned int line_number)
{
    stack_t *temp = *stack;

    if (!*stack)
    {
        fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
        free_stack(stack);
        exit(EXIT_FAILURE);
    }

    *stack = (*stack)->next;
    free(temp);
}