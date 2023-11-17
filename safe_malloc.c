#include "monty.h"

/**
 * safe_malloc - Allocate memory safely
 *
 * @size: Allocated memory size.
 * @stack: stack address.
 *
 * Return: Address of the allocated memroy.
*/
void *safe_malloc(size_t size, stack_t *stack)
{
	void *new_node = malloc(size);

	if (new_node == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		fclose(fd);
		free(buffer);
		free(safe_buffer);
		free_stqu(stack);
		exit(EXIT_FAILURE);
	}
	return (new_node);
}
