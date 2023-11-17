#include "monty.h"

/**
 * opcode_handler - hanldes opcodes.
 *
 * @stack: current node.
 * @line_number: the new node's data.
 *
 */
void (*opcode_handler(char *opcode))(stack_t **stack, unsigned int line_number)
{
	int index;
	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};

	for (index = 0; opcodes[index].opcode != NULL; index++)
	{
		if (strcmp(opcode, opcodes[index].opcode) == 0)
			return (opcodes[index].f);
	}

	return (NULL);
}
