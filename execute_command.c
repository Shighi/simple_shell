#include "shell.h"

/**
 * is_builtin - Checks if a command is a built-in function
 * @command: The command to check
 * Return: 1 if the command is built-in, 0 otherwise
 */
int is_builtin(char *command)
{
	char *builtins[] = {"exit", "env", "setenv", "unsetenv", "cd", "alias", NULL};
	int i;

	for (i = 0; builtins[i]; i++)
	{
		if (_strcmp(command, builtins[i]) == 0)
			return (1);
	}
	return (0);
}

/**
 * execute_builtin - Executes a built-in command
 * @args: Array of command arguments
 * Return: Result of the built-in command execution
 */
int execute_builtin(char **args)
{
	if (_strcmp(args[0], "exit") == 0)
		return (shell_exit(args));
	else if (_strcmp(args[0], "env") == 0)
		return (shell_env(args));
	else if (_strcmp(args[0], "setenv") == 0)
		return (shell_setenv(args));
	else if (_strcmp(args[0], "unsetenv") == 0)
		return (shell_unsetenv(args));
	else if (_strcmp(args[0], "cd") == 0)
		return (shell_cd(args));
	else if (_strcmp(args[0], "alias") == 0)
		return (shell_alias(args));

	return (1);
}

/**
 * execute_command - Executes the command provided by the user
 * @args: Array of command arguments
 * Return: 1 if the shell should continue running, 0 if it should terminate
 */
int execute_command(char **args)
{
	pid_t pid;
	int status;

	if (args[0] == NULL)
		return (1);

	if (is_builtin(args[0]))
		return (execute_builtin(args));

	pid = fork();
	if (pid == 0)
	{
		char *command_path = find_command(args[0]);

		if (command_path == NULL)
		{
			fprintf(stderr, "%s: command not found\n", args[0]);
			exit(EXIT_FAILURE);
		}

		if (execve(command_path, args, environ) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		perror("fork");
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (1);
}
