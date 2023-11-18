#include "monty.h"

void safe_mod(stack_t *stack, int line_number);
void check_mod(int n, stack_t *stack, unsigned int line);

/**
 * mod - module the top 2 nodes data.
 *
 * @stack: current node.
 * @line_number: number of the line in the monty bytecode file.
 *
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL, *temp_node = NULL, *new_node = NULL;
	int sum = 0;

	if (stack == NULL)
		return;

	temp = *stack;
	if (temp == NULL)
		safe_mod(*stack, line_number);

	while (temp->next != NULL)
		temp = temp->next;

	if (temp != NULL)
	{
		if (temp->prev == NULL)
			safe_mod(*stack, line_number);
		check_mod(temp->n, *stack, line_number);
		sum += temp->n;
		temp_node = temp;
		temp = temp->prev;
		temp->next = NULL;
		sum %= temp->n;
		free(temp_node);

		temp_node = temp;
		if (temp->prev != NULL)
		{
			temp = temp->prev;
			temp->next = NULL;
		}

		new_node = safe_malloc(sizeof(stack_t), *stack);
		new_node->n = sum;
		new_node->next = NULL;
		if (temp_node->prev != NULL)
		{
			temp->next = new_node;
			new_node->prev = temp;
		}
		else
		{
			new_node->prev = NULL;
			*stack = new_node;
		}
		free(temp_node);
	}
}


/**
 * safe_mod - handle mod errors.
 *
 * @stack: stack.
 * @line_number: line number
*/
void safe_mod(stack_t *stack, int line_number)
{
	dprintf(STDERR_FILENO, "L%i: can't mod, stack too short\n", line_number);
	safe_exit(stack);
}

/**
 * check_mod - check 0 division
 *
 * @n: number to be checked.
 * @stack: stack_t linked list.
 * @line: number of the line in the file.
*/
void check_mod(int n, stack_t *stack, unsigned int line)
{
	if (n == 0)
	{
		dprintf(STDERR_FILENO, "L%i: division by zero", line);
		safe_exit(stack);
	}
}
