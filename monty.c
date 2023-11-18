#include "monty.h"

void opcode_error_handle(unsigned int line_number);
void handle_args(int argu_c, char **argu_v);

char *token = NULL, *buffer = NULL, *safe_buffer = NULL;
FILE *fd = NULL;

/**
 * main - create an interpreter for Monty ByteCodes files.
 *
 * @argc: number of arguments.
 * @argv: arguments' values.
 *
 * Return: (EXIT_SUCCESS) always success, (EXIT_FAILURE) otherwise.
 */
int main(int argc, char **argv)
{
	unsigned int line_number = 0;
	ssize_t line_length;
	size_t buffer_size;
	stack_t *stack_queue = NULL;

	handle_args(argc, argv);
	while (1)
	{
		line_length = getline(&buffer, &buffer_size, fd);
		if (line_length == -1)
			break;
		line_number++;
		if (line_length == 1)
			continue;

		safe_buffer = safeBuffer(buffer);
		token = strtok(safe_buffer, " ");
		if (token == NULL || strncmp(token, "#", 1) == 0)
		{
			free(safe_buffer);
			continue;
		}

		instruction = opcode_handler(token);
		if (instruction == NULL)
			opcode_error_handle(line_number);

		instruction(&stack_queue, line_number);
		free(safe_buffer);
	};

	free(buffer);
	fclose(fd);
	free_stqu(stack_queue);
	return (EXIT_SUCCESS);
}

/**
 * opcode_error_handle - handles NULL opcode
 *
 * @line_number: line number in the file.
 *
*/
void opcode_error_handle(unsigned int line_number)
{
	dprintf(STDERR_FILENO, "L%d: unknown instruction %s\n", line_number, token);
	fclose(fd);
	free(buffer);
	free(safe_buffer);
	exit(EXIT_FAILURE);
}


/**
 * handle_args - handle arguments.
 *
 * @argu_c: arguments' number.
 * @argu_v: arguments' values
*/
void handle_args(int argu_c, char **argu_v)
{
	if (argu_c == 1 || argu_c > 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argu_v[1], "r");
	if (fd == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argu_v[1]);
		exit(EXIT_FAILURE);
	}
}
