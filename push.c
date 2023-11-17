#include "monty.h"

/**
 * push - pushes an element to the stack
 *
 * @stack: pointer to the stack
 * @line_number: line number of the opcode
 */

void push(stack_t **stack, unsigned int line_number)
{
    char *n = strtok(NULL, " \n\t\r");
    int num;

    if (!n || !is_number(n))
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        free_stack(stack);
        exit(EXIT_FAILURE);
    }

    num = atoi(n);

    if (add_node(stack, num) == EXIT_FAILURE)
    {
        fprintf(stderr, "Error: malloc failed\n");
        free_stack(stack);
        exit(EXIT_FAILURE);
    }
}
