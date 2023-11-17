# Monty ByteCode Interpreter

## 0x19. C - Stacks, Queues - LIFO, FIFO

## Overview

The Monty ByteCode Interpreter is a project for a scripting language called Monty. The interpreter reads Monty byte code files with the `.m` extension and executes the specified instructions on a unique stack. This project is part of ALX Software Engineering Program and implements a custom stack data structure to manipulate the stack based on the given Monty instructions.

## Learning Objectives

- What do LIFO and FIFO mean
- What is a stack, and when to use it
- What is a queue, and when to use it
- What are the common implementations of stacks and queues
- What are the most common use cases of stacks and queues
- What is the proper way to use global variables

## Features

- Monty ByteCode Instructions: Supports a variety of Monty instructions such as `push`, `pop`, `add`, `sub`, `mul`, `div`, `mod`, `pall`, `pint`, and more.

- Custom Stack: Utilizes a doubly linked list as a custom stack data structure.

- Error Handling: Provides error messages and exits gracefully in case of various errors, including invalid instructions, file opening issues, stack underflow, and memory allocation failures.

## Compilation

Compile the program using the following command:

```
$ gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
```

## Usage

Run the Monty interpreter by providing a Monty byte code file as an argument:

```
$ ./monty file.m
```

## Monty ByteCode Files

Monty byte code files have the extension .m and follow specific formatting rules:

- One instruction per line.
- Any number of spaces before or after the opcode and its argument.
- Blank lines are allowed.

## Example Monty ByteCode File

```
julien@ubuntu:~/monty$ cat -e bytecodes/000.m
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$

julien@ubuntu:~/monty$ cat -e bytecodes/00.m
push 1$
push 2$
push 3$
pall$
julien@ubuntu:~/monty$ ./monty bytecodes/00.m
3
2
1
julien@ubuntu:~/monty$
```

## Error Handling

The interpreter provides detailed error messages for common issues:

- Incorrect usage: `Usage: ./monty file`
- File opening failure: `Error: Can't open file <file>`
- Unknown instruction: `L<line_number>: unknown instruction <opcode>`
- Stack underflow: `Error: can't pop an empty stack`
- Memory allocation failure: `Error: malloc failed`

## Contributing

Feel free to contribute to the project by opening issues or submitting pull requests.

## License

This project is licensed under the [MIT License](/LICENSE).
