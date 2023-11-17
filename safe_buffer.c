#include "monty.h"

/**
 * safeBuffer - delete the last character '\n'.
 *
 * @buffer: buffer to processed.
 *
 * Return: pointer to the safe buffer.
 */
char *safeBuffer(char *buffer)
{
	char *safe_buffer = NULL;
	int index, len;

	for (len = 0; buffer[len + 1];)
		len++;

	safe_buffer = safe_malloc(len + 1, NULL);

	for (index = 0; index < len; index++)
		safe_buffer[index] = buffer[index];

	safe_buffer[index] = '\0';
	return (safe_buffer);
}
