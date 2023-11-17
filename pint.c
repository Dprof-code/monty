#include "monty.h"

/**
 * pint - prints the value at the top of the stack
 *
 * @stack: pointer to the stack
 * @line_number: line number of the opcode
 */

void pint(stack_t **stack, unsigned int line_number)
{
    if (!*stack)
    {
        fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
        free_stack(stack);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", (*stack)->n);
}