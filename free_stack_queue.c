#include "monty.h"

/**
 * free_stqu - frees a stack_t list.
 *
 * @head: current node.
 *
 */
void free_stqu(stack_t *head)
{
	stack_t *temp = NULL;
	if (head == NULL)
		return;

	temp = head;
	while (temp->prev != NULL)
		temp = temp->prev;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
