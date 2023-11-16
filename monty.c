#include "monty.h"

char *token = NULL;
FILE *fd;

int main(int argc, char **argv)
{
	unsigned int line_number = 0;
	ssize_t line_length;
	size_t buffer_size;
	char *buffer = NULL, *safe_buffer = NULL;
	stack_t *stack_queue = NULL;

	if (argc == 1 || argc > 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");
	if (fd == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

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
		if (token == NULL || strcmp(token, "#") == 0)
			continue;
		dprintf(STDOUT_FILENO, "token: %s\t", token);

		instruction = opcode_handler(token);
		if (instruction == NULL)
		{
			dprintf(STDERR_FILENO, "L%d: unknown instruction %s\n", line_number, token);
			fclose(fd);
			free(buffer);
			free(safe_buffer);
			exit(EXIT_FAILURE);
		}
		instruction(&stack_queue, line_number);
		free(safe_buffer);
	};

	free(buffer);
	fclose(fd);
	free_stqu(&stack_queue);
	return (0);
}
