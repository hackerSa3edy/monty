#include "monty.h"

/**
 * push - adds a new node at the end of a stack_t list.
 *
 * @stack: current node.
 * @line_number: number of the line in the monty bytecode file.
 *
 */
void push(stack_t **head, unsigned int line_number)
{
	stack_t *temp = NULL, *new_node = NULL;
	int n;

	if (head == NULL)
		return;

	token = strtok(NULL, " ");
	if (token == NULL)
	{
		dprintf(STDERR_FILENO, "L%i: usage: push integer", line_number);
		fclose(fd);
		free(buffer);
		free(safe_buffer);
		free_stqu(*head);
		exit(EXIT_FAILURE);
	}
	n = atoi(token);

	if (*head == NULL)
	{
		*head = malloc(sizeof(stack_t));

		if (*head == NULL)
		{
			fclose(fd);
			free(buffer);
			free(safe_buffer);
			exit(EXIT_FAILURE);
		}
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
