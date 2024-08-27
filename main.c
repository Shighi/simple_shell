#include "shell.h"

int status = 0;

/**
 * main - Entry point for the simple shell program
 * @argc: Argument count
 * @argv: Argument vector
 * Return: 0 on success, or an error code on failure
 */
int main(int argc, char **argv)
{
	char *input;
	int run_status = 1;
	int is_interactive = isatty(STDIN_FILENO);

	(void)argc;

	if (argc == 2)
		return (process_file(argv[1]));

	while (run_status)
	{
		if (is_interactive)
			_puts("$ ");

		input = read_input();
		if (input == NULL)
		{
			if (is_interactive)
				_puts("\n");
			break;
		}

		run_status = handle_logical_operators(input);
		status = run_status;

		free(input);
	}

	return (status);
}
