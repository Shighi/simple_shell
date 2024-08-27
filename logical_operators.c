#include "shell.h"

/**
 * execute_command_list - Executes a list of commands
 * @commands: Array of command strings
 * @num_commands: Number of commands in the array
 * Return: Status of the last executed command
 */
int execute_command_list(char **commands, int num_commands)
{
	int i, status = 0;
	char **args;

	for (i = 0; i < num_commands; i++)
	{
		args = parse_input(commands[i]);
		status = execute_command(args);
		free(args);

		if (i < num_commands - 1)
		{
			if ((commands[i + 1][0] == '&' && status != 0) ||
				(commands[i + 1][0] == '|' && status == 0))
			{
				i++;  /* Skip the next command */
			}
		}
	}

	return (status);
}

/**
 * handle_logical_operators - Handles && and || operators
 * @input: The input string
 * Return: Status of the last executed command
 */
int handle_logical_operators(char *input)
{
	char *token, *saveptr;
	char *delimiters = "&|;";
	char **commands = NULL;
	int num_commands = 0;
	int status;

	token = strtok_r(input, delimiters, &saveptr);
	while (token != NULL)
	{
		commands = realloc(commands, sizeof(char *) * (num_commands + 1));
		commands[num_commands] = token;
		num_commands++;

		if (*saveptr == '&' || *saveptr == '|' || *saveptr == ';')
		{
			commands = realloc(commands, sizeof(char *) * (num_commands + 1));
			commands[num_commands] = saveptr;
			num_commands++;
			saveptr++;
		}

		token = strtok_r(NULL, delimiters, &saveptr);
	}

	status = execute_command_list(commands, num_commands);

	free(commands);
	return (status);
}
