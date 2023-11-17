#include "monty.h"

/**
 * pint - print the top.
 *
 * @stack: current node.
 * @line_number: the new node's data.
 *
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void) line_number;
	if (stack == NULL)
		return;
	temp = *stack;
	if (temp != NULL)
		dprintf(STDOUT_FILENO, "%i\n", temp->n);
}
