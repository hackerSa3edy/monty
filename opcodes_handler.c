#include "monty.h"

void (*opcode_handler(char *opcode))(stack_t **stack, unsigned int line_number)
{
	int index;
	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	for (index = 0; opcodes[index].opcode != NULL; index++)
	{
		if (strcmp(opcode, opcodes[index].opcode) == 0)
		{
			instruction = opcodes[index].f;
			break;
		}
	}

	return (instruction);
}
