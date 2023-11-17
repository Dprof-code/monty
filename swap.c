#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 *
 * @stack: pointer to the stack
 * @line_number: line number of the opcode
 */

void swap(stack_t **stack, unsigned int line_number)
{
    int temp;

    if (!*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
        free_stack(stack);
        exit(EXIT_FAILURE);
    }

    temp = (*stack)->n;
    (*stack)->n = (*stack)->next->n;
    (*stack)->next->n = temp;
}