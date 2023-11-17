#include "monty.h"

/**
 * pop - deletes the last element
 *
 * @stack: current node.
 * @line_number: the new node's data.
 *
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL, *temp_node = NULL;

	if (stack == NULL)
		return;

	temp = *stack;
	if (temp != NULL)
	{
		temp_node = temp;
		temp = temp->prev;
		if (temp != NULL)
			temp->next = NULL;
		free(temp_node);
		*stack = temp;
	}
	else
	{
		dprintf(STDOUT_FILENO, "L%i: can't pop an empty stack", line_number);
		fclose(fd);
		free(buffer);
		free(safe_buffer);
		exit(EXIT_FAILURE);
	}
}
