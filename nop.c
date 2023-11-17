#include "monty.h"

/**
 * nop - do nothing.
 *
 * @stack: current node.
 * @line_number: number of the line in the monty bytecode file.
 *
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
