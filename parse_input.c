#include "shell.h"

/**
 * parse_input - Parses user input into command arguments
 * @input: The input string from the user
 *
 * Return: Array of command arguments
 */
char **parse_input(char *input)
{
	int bufsize = 64, position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token, **tokens_backup;

	if (!tokens)
	{
		perror("allocation error");
		exit(EXIT_FAILURE);
	}

	token = strtok(input, " \t\r\n\a");
	while (token != NULL)
	{
		tokens[position] = _strdup(token);
		position++;

		if (position >= bufsize)
		{
			bufsize += 64;
			tokens_backup = tokens;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				free(tokens_backup);
				perror("allocation error");
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, " \t\r\n\a");
	}
	tokens[position] = NULL;
	replace_variables(tokens);
	return (tokens);
}

/**
 * replace_variables - Replaces variables in the command arguments
 * @args: The command arguments
 */
void replace_variables(char **args)
{
	int i;
	char *value;

	for (i = 0; args[i] != NULL; i++)
	{
		if (args[i][0] == '$')
		{
			if (_strcmp(args[i], "$$") == 0)
			{
				free(args[i]);
				args[i] = _strdup(pid_to_str(getpid()));
			}
			else if (_strcmp(args[i], "$?") == 0)
			{
				free(args[i]);
				args[i] = _strdup(int_to_str(status));
			}
			else
			{
				value = _getenv(args[i] + 1);
				if (value != NULL)
				{
					free(args[i]);
					args[i] = _strdup(value);
				}
			}
		}
	}
}
