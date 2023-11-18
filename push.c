#include "monty.h"

void push_errors_handle(stack_t *head, unsigned int line);
/**
 * push - adds a new node at the end of a stack_t list.
 *
 * @head: current node.
 * @line_number: number of the line in the monty bytecode file.
 *
 */
void push(stack_t **head, unsigned int line_number)
{
	stack_t *temp = NULL, *new_node = NULL;
	int n, index;

	if (head == NULL)
		return;

	token = strtok(NULL, " ");
	if (token == NULL)
		push_errors_handle(*head, line_number);
	for (index = 0; token[index]; index++)
		if (!isdigit(token[index]) && token[index] != '-')
			push_errors_handle(*head, line_number);

	n = atoi(token);

	if (*head == NULL)
	{
		*head = safe_malloc(sizeof(stack_t), NULL);
		(*head)->n = n;
		(*head)->prev = NULL;
		(*head)->next = NULL;

		return;
	}

	temp = *head;
	if (temp == NULL)
		return;
	while (temp->next != NULL)
		temp = temp->next;

	new_node = safe_malloc(sizeof(stack_t), *head);

	new_node->n = n;
	new_node->next = NULL;
	temp->next = new_node;
	new_node->prev = temp;
}


/**
 * push_errors_handle - handle push errors
 *
 * @stack: stack_t linked list
 * @line: line number
*/
void push_errors_handle(stack_t *head, unsigned int line)
{
	dprintf(STDERR_FILENO, "L%i: usage: push integer\n", line);
	safe_exit(head);
}
