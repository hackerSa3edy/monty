#include "monty.h"

/**
 * pstr - print all nodes as stirng.
 *
 * @stack: current node.
 * @line_number: number of the line in the monty bytecode file.
 *
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void) line_number;
	if (stack == NULL)
		return;
	temp = *stack;
	if (temp == NULL)
		return;

	while (temp->next != NULL)
		temp = temp->next;

	while (temp != NULL)
	{
		if (temp->n <= 0 || temp->n > 127)
			break;
		dprintf(STDOUT_FILENO, "%c", temp->n);
		temp = temp->prev;
	}
	dprintf(STDOUT_FILENO, "%s", "\n");
}
