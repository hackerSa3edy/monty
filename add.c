#include "monty.h"

void safe_add(stack_t *stack, int line_number);

/**
 * add - sum the top 2 nodes data.
 *
 * @stack: current node.
 * @line_number: number of the line in the monty bytecode file.
 *
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL, *temp_node = NULL, *new_node = NULL;
	int sum = 0;

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
			safe_add(*stack, line_number);

		sum += temp->n;
		temp_node = temp;
		temp = temp->prev;
		temp->next = NULL;
		sum += temp->n;
		free(temp_node);

		temp_node = temp;
		temp = temp->prev;
		temp->next = NULL;
		free(temp_node);

		new_node = safe_malloc(sizeof(stack_t), *stack);
		new_node->n = sum;
		new_node->next = NULL;
		temp->next = new_node;
		new_node->prev = temp;
	}
}


/**
 * safe_add - handle add errors.
 *
 * @stack: stack.
 * @line_number: line number
*/
void safe_add(stack_t *stack, int line_number)
{
	dprintf(STDERR_FILENO, "L%i: can't add, stack too short\n", line_number);
	fclose(fd);
	free(buffer);
	free(safe_buffer);
	free_stqu(stack);
	exit(EXIT_FAILURE);
}
