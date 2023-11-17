#include "monty.h"

/**
 * is_number - checks if a string is a number
 *
 * @str: string to check
 * Return: 1 if true, 0 if false
 */

int is_number(char *str)
{
    int i = 0;

    if (str[0] == '-')
        i++;

    for (; str[i]; i++)
    {
        if (str[i] < '0' || str[i] > '9')
            return (0);
    }

    return (1);
}

/**
 * add_node - adds a node to the stack
 *
 * @stack: pointer to the stack
 * @n: value of the node
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */

int add_node(stack_t **stack, int n)
{
    stack_t *new = malloc(sizeof(stack_t));

    if (!new)
        return (EXIT_FAILURE);

    new->n = n;
    new->prev = NULL;
    new->next = *stack;

    if (*stack)
        (*stack)->prev = new;

    *stack = new;

    free (new);
    free (*stack);

    return (EXIT_SUCCESS);
}

/**
 * free_stack - frees a stack
 *
 * @stack: pointer to the stack
 */

void free_stack(stack_t **stack)
{
    stack_t *temp = *stack;

    while (*stack)
    {
        temp = (*stack)->next;
        free(*stack);
        *stack = temp;
    }
}
