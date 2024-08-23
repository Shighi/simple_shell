#include "shell.h"

/**
 * shell_exit - Builtin command: exit
 * @args: Arguments
 *
 * Return: Always returns 0, to terminate execution
 */
int shell_exit(char **args)
{
	if (args[1] != NULL)
	{
		int status = atoi(args[1]);

		exit(status);
	}
	exit(0);
}

/**
 * shell_env - Builtin command: env
 * @args: Arguments
 *
 * Return: Always returns 1, to continue execution
 */
int shell_env(char **args)
{
	int i;

	(void)args;

	for (i = 0; environ[i] != NULL; i++)
	{
		_puts(environ[i]);
		_putchar('\n');
	}

	return (1);
}

/**
 * shell_setenv - Builtin command: setenv
 * @args: Arguments
 *
 * Return: Always returns 1, to continue execution
 */
int shell_setenv(char **args)
{
	if (args[1] == NULL || args[2] == NULL)
	{
		fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
		return (1);
	}

	if (_setenv(args[1], args[2], 1) != 0)
	{
		perror("setenv");
	}

	return (1);
}

/**
 * shell_unsetenv - Builtin command: unsetenv
 * @args: Arguments
 *
 * Return: Always returns 1, to continue execution
 */
int shell_unsetenv(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "Usage: unsetenv VARIABLE\n");
		return (1);
	}

	if (_unsetenv(args[1]) != 0)
	{
		perror("unsetenv");
	}

	return (1);
}

/**
 * shell_cd - Builtin command: cd
 * @args: Arguments
 *
 * Return: Always returns 1, to continue execution
 */
int shell_cd(char **args)
{
	char *dir = args[1];
	char cwd[1024];
	char *home = _getenv("HOME");

	if (dir == NULL)
	{
		dir = home;
	}
	else if (_strcmp(dir, "-") == 0)
	{
		dir = _getenv("OLDPWD");
	}

	if (chdir(dir) == 0)
	{
		getcwd(cwd, sizeof(cwd));
		_setenv("OLDPWD", _getenv("PWD"), 1);
		_setenv("PWD", cwd, 1);
	}
	else
	{
		perror("cd");
	}

	return (1);
}
