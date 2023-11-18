#include "monty.h"

/**
 * safe_exit - handle push errors
 *
 * @stack: stack_t linked list
*/
void safe_exit(stack_t *stack)
{
	fclose(fd);
	free(buffer);
	free(safe_buffer);
	free_stqu(stack);
	exit(EXIT_FAILURE);
}
