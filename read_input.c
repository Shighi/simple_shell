#include "shell.h"

/**
 * read_input - Reads input from the user
 *
 * Return: Pointer to the input string
 */
char *read_input(void)
{
	char *input = NULL;
	size_t bufsize = 0;
	ssize_t characters;

	characters = getline(&input, &bufsize, stdin);

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
