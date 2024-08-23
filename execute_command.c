#include "shell.h"

/**
 * execute_command - Executes the command provided by the user
 * @args: Array of command arguments
 *
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
		/* Child process */
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
		/* Parent process */
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (1);
}

/**
 * find_command - Finds the full path of a command
 * @command: The command to find
 *
 * Return: Full path of the command if found, NULL otherwise
 */
char *find_command(char *command)
{
	char *path, *path_copy, *path_token, *file_path;
	int command_length, directory_length;
	struct stat buffer;

	path = _getenv("PATH");
	if (path)
	{
		path_copy = _strdup(path);
		command_length = strlen(command);
		path_token = strtok(path_copy, ":");
		while (path_token != NULL)
		{
			directory_length = strlen(path_token);
			file_path = malloc(command_length + directory_length + 2);
			strcpy(file_path, path_token);
			strcat(file_path, "/");
			strcat(file_path, command);
			if (stat(file_path, &buffer) == 0)
			{
				free(path_copy);
				return (file_path);
			}
			else
			{
				free(file_path);
				path_token = strtok(NULL, ":");
			}
		}
		free(path_copy);
		if (stat(command, &buffer) == 0)
			return (_strdup(command));
		return (NULL);
	}
	if (stat(command, &buffer) == 0)
		return (_strdup(command));
	return (NULL);
}
