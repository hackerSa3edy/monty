#include "monty.h"

void push(stack_t **stack, unsigned int line_number)
{
	dprintf(STDOUT_FILENO, "hello dude - push L%d\n", line_number);
	if (stack == NULL)
		return;
}
