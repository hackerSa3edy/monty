#include "monty.h"

/**
 * safe_exit - handle push errors
 *
 * @stack: stack_t linked list
 * @line: line number
*/
void safe_exit(stack_t *stack, unsigned int line)
{
	fclose(fd);
	free(buffer);
	free(safe_buffer);
	free_stqu(stack);
	exit(EXIT_FAILURE);
}
