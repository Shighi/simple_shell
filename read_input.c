#include "shell.h"

/**
 * _getline - Custom implementation of getline
 * @lineptr: Pointer to the buffer storing the read line
 * @n: Pointer to the size of the buffer
 * @stream: File stream to read from
 * Return: Number of characters read, or -1 on failure
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	static char buffer[BUFFER_SIZE];
	static size_t buffer_pos = 0;
	static size_t buffer_size = 0;
	size_t pos = 0;
	int c;

	if (lineptr == NULL || n == NULL || stream == NULL)
		return (-1);

	if (*lineptr == NULL)
	{
		*n = BUFFER_SIZE;
		*lineptr = malloc(*n);
		if (*lineptr == NULL)
			return (-1);
	}

	while (1)
	{
		if (buffer_pos >= buffer_size)
		{
			buffer_size = read(fileno(stream), buffer, BUFFER_SIZE);
			buffer_pos = 0;
			if (buffer_size <= 0)
				return (pos == 0 ? -1 : pos);
		}

		c = buffer[buffer_pos++];

		if (pos >= *n - 1)
		{
			*n *= 2;
			*lineptr = realloc(*lineptr, *n);
			if (*lineptr == NULL)
				return (-1);
		}

		(*lineptr)[pos++] = c;

		if (c == '\n')
			break;
	}

	(*lineptr)[pos] = '\0';
	return (pos);
}

/**
 * read_input - Reads input from the user
 * Return: Pointer to the input string
 */
char *read_input(void)
{
	char *input = NULL;
	size_t bufsize = 0;
	ssize_t characters;

	characters = _getline(&input, &bufsize, stdin);

	if (characters == -1)
	{
		free(input);
		return (NULL);
	}

	if (input[characters - 1] == '\n')
		input[characters - 1] = '\0';

	handle_comments(input);

	return (input);
}

/**
 * handle_comments - Removes comments from the input
 * @input: The input string
 */
void handle_comments(char *input)
{
	char *comment_pos = _strchr(input, '#');

	if (comment_pos != NULL)
		*comment_pos = '\0';
}
