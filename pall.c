#include "monty.h"

/**
 * pall - print all nodes.
 *
 * @stack: current node.
 * @line_number: the new node's data.
 *
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void) line_number;
	if (stack == NULL)
		return;
	temp = *stack;
	while (temp != NULL)
	{
		dprintf(STDOUT_FILENO, "%i\n", temp->n);
		temp = temp->prev;
	}
}
