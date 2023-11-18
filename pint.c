#include "monty.h"

/**
 * pint - print the top.
 *
 * @stack: current node.
 * @line_number: number of the line in the monty bytecode file.
 *
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void) line_number;
	if (stack == NULL)
		return;
	temp = *stack;
	if (temp == NULL)
	{
		dprintf(STDERR_FILENO, "L%i: can't pint, stack empty\n", line_number);
		safe_exit(*stack);
	}
	while (temp->next != NULL)
		temp = temp->next;

	if (temp != NULL)
		dprintf(STDOUT_FILENO, "%i\n", temp->n);
}
