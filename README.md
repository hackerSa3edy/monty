# Project: 0x19. C - Stacks, Queues - LIFO, FIFO

This project is an interpreter for Monty ByteCodes files. It implements a stack (Last In, First Out) and a queue (First In, First Out) in C.

## Learning Objectives

- What do LIFO and FIFO mean
- What is a stack, and when to use it
- What is a queue, and when to use it
- What are the common implementations of stacks and queues
- What are the most common use cases of stacks and queues
- What is the proper way to use global variables

## Tasks

Each task corresponds to a specific opcode implementation:

| Task          | File                                   |
| ------------- | -------------------------------------- |
| 0. push, pall | [push.c](./push.c), [pall.c](./pall.c) |
| 1. pint       | [pint.c](./pint.c)                     |
| 2. pop        | [pop.c](./pop.c)                       |
| 3. swap       | [swap.c](./swap.c)                     |
| 4. add        | [add.c](./add.c)                       |
| 5. nop        | [nop.c](./nop.c)                       |
| 6. sub        | [sub.c](./sub.c)                       |
| 7. div        | [div.c](./div.c)                       |
| 8. mul        | [mul.c](./mul.c)                       |

## Getting Started

To get a local copy up and running, follow these steps:

1. Clone the repository:

   ```sh
   git clone https://github.com/hackerSa3edy/monty.git
   ```

2. Navigate to the project directory:

   ```sh
   cd monty
   ```

3. Compile the project:

   ```sh
   gcc -Wall -Werror -Wextra -pedantic *.c -o monty
   ```

## Usage

To run the Monty interpreter, compile all .c files in the repository and run the output file with a .m file as an argument:

```bash
gcc -Wall -Werror -Wextra -pedantic *.c -o monty
./monty bytecodes/00.m
```

The .m files in the [bytecodes/](./bytecodes/) directory are test files in the Monty bytecodes format.
To run the interpreter, use the following command:

```sh
./monty <file.m>
```

Where `<file.m>` is the path to a Monty bytecodes file.

## Monty ByteCodes Files

Monty bytecodes files contain a list of commands to be executed by the interpreter. Each command must be on its own line. Lines can be empty or contain a comment (lines starting with `#` are treated as comments).

### Commands

The interpreter supports the following commands:

- `push <n>`: Pushes an integer `<n>` onto the top of the stack.
- `pall`: Prints all values on the stack.
- `pint`: Prints the value at the top of the stack.
- `pop`: Removes the top element of the stack.
- `swap`: Swaps the top two elements of the stack.
- `add`: Adds the top two elements of the stack.
- `nop`: Does nothing.
- `sub`: Subtracts the top element of the stack from the second top element.
- `div`: Divides the second top element of the stack by the top element.
- `mul`: Multiplies the top two elements of the stack.
- `mod`: Computes the remainder of the division of the second top element by the top element.
- `pchar`: Prints the char at the top of the stack.
- `pstr`: Prints the string starting at the top of the stack.

## Author

- [Abdelrahman Mohamed](https://x.com/hackersa3edy)
- Project Link: [https://github.com/hackerSa3edy/monty.git](https://github.com/hackerSa3edy/monty.git)
