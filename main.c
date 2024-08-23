#include "shell.h"

/**
 * main - Entry point for the simple shell program
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: 0 on success, or an error code on failure
 */
int main(int argc, char **argv)
{
	char *input;
	char **args;
	int status = 1;
	int is_interactive = isatty(STDIN_FILENO);

	(void)argc;

	if (argc == 2)
		return (process_file(argv[1]));

	while (status)
	{
		if (is_interactive)
			_puts("$ ");

		input = read_input();
		if (input == NULL) /* EOF (Ctrl+D) condition */
		{
			if (is_interactive)
				_puts("\n");
			break;
		}

		args = parse_input(input);
		status = execute_command(args);

		free(input);
		free(args);
	}

	return (0);
}
