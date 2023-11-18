#include "monty.h"

/**
 * pchar - print the top as char.
 *
 * @stack: current node.
 * @line_number: number of the line in the monty bytecode file.
 *
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void) line_number;
	if (stack == NULL)
		return;
	temp = *stack;
	if (temp == NULL)
	{
		dprintf(STDERR_FILENO, "L%i: can't pchar, stack empty\n", line_number);
		safe_exit(*stack);
	}
	while (temp->next != NULL)
		temp = temp->next;

	if (temp != NULL)
	{
		if (temp->n >= 0 && temp->n <= 127)
			dprintf(STDOUT_FILENO, "%c\n", temp->n);
		else
		{
			dprintf(STDERR_FILENO, "L%i: can't pchar, value out of range\n",
					line_number);
			safe_exit(*stack);
		}
	}
}
