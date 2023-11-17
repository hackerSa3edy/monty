#include "monty.h"


/**
 * swap - swap 2 nodes data.
 *
 * @stack: current node.
 * @line_number: number of the line in the monty bytecode file.
 *
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL, *temp_node = NULL;

	if (stack == NULL)
		return;

	temp = *stack;
	if (temp == NULL)
		return;
	while (temp->next != NULL)
		temp = temp->next;

	if (temp != NULL)
	{
		if (temp->prev == NULL)
		{
			dprintf(STDERR_FILENO, "L%i: can't swap, stack too short\n", line_number);
			fclose(fd);
			free(buffer);
			free(safe_buffer);
			free_stqu(*stack);
			exit(EXIT_FAILURE);
		}

		temp_node = temp->prev;

		temp->prev = temp_node->prev;
		temp->next = temp_node;

		(temp_node->prev)->next = temp;
		temp_node->prev = temp;
		temp_node->next = NULL;
	}
}
