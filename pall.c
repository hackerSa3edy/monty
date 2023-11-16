#include "monty.h"

void pall(stack_t **stack, unsigned int line_number)
{
	dprintf(STDOUT_FILENO, "hello dude - pall L%d\n", line_number);
	if (stack == NULL)
		return;
}
