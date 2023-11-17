#include "monty.h"

/**
 * add - adds the top two elements of the stack
 *
 * @stack: pointer to the stack
 * @line_number: line number of the opcode
 */

void add(stack_t **stack, unsigned int line_number)
{
    int sum;

    if (!*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
        free_stack(stack);
        exit(EXIT_FAILURE);
    }

    sum = (*stack)->n + (*stack)->next->n;
    pop(stack, line_number);
    (*stack)->n = sum;
}