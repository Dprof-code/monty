#include "monty.h"

int main(int argc, char *argv[])
{
    FILE *file = fopen(argv[1], "r");
    stack_t *stack = NULL;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if (parse_file(file, &stack) == EXIT_FAILURE)
    {
        fclose(file);
        free_stack(&stack);
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    return (EXIT_SUCCESS);
}

/**
 * parse_file - parses a file for monty opcodes
 *
 * @file: file to parse
 * @stack: pointer to the stack
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */

int parse_file(FILE *file, stack_t **stack)
{
    char *line = NULL;
    size_t len = 0;
    unsigned int line_number = 0;
    instruction_t instruction = {NULL, NULL};
    char *opcode = NULL;

    while (getline(&line, &len, file) != -1)
    {
        line_number++;
        opcode = strtok(line, " \n\t\r");
        if (opcode)
        {
            instruction = get_instruction(opcode);
            if (instruction.f)
                instruction.f(stack, line_number);
            else
            {
                fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
                free(line);
                return (EXIT_FAILURE);
            }
        }
    }

    free(line);
    fclose(file);
    return (EXIT_SUCCESS);
}

/**
 * get_instruction - gets the instruction from the opcode
 *
 * @opcode: opcode to check
 * Return: instruction_t struct with opcode and function
 */

instruction_t get_instruction(char *opcode)
{
    instruction_t instruction = {NULL, NULL};
    instruction_t instructions[] = {
        {"push", push},
        {"pall", pall},
        {"pint", pint},
        {"pop", pop},
        {"swap", swap},
        {"add", add},
        {"nop", nop},
        {NULL, NULL}};

    int i = 0;

    while (instructions[i].opcode)
    {
        if (strcmp(instructions[i].opcode, opcode) == 0)
        {
            instruction.opcode = instructions[i].opcode;
            instruction.f = instructions[i].f;
            break;
        }
        i++;
    }

    return (instruction);
}
