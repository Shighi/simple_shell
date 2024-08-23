#include "shell.h"

/**
 * _getenv - Gets the value of an environment variable
 * @name: Name of the environment variable
 *
 * Return: The value of the environment variable, or NULL if it doesn't exist
 */
char *_getenv(const char *name)
{
	int i, len;

	len = strlen(name);
	for (i = 0; environ[i]; i++)
	{
		if (strncmp(name, environ[i], len) == 0 && environ[i][len] == '=')
		{
			return (&environ[i][len + 1]);
		}
	}
	return (NULL);
}

/**
 * _setenv - Change or add an environment variable
 * @name: Name of the environment variable
 * @value: Value of the environment variable
 * @overwrite: If non-zero, overwrite the variable if it exists
 *
 * Return: 0 on success, -1 on error
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	char *env_var;
	int len;

	if (!name || !value)
		return (-1);
	if (!overwrite && _getenv(name))
		return (0);
	len = strlen(name) + strlen(value) + 2;
	env_var = malloc(len);
	if (!env_var)
		return (-1);
	snprintf(env_var, len, "%s=%s", name, value);
	if (putenv(env_var) != 0)
	{
		free(env_var);
		return (-1);
	}
	return (0);
}

/**
 * _unsetenv - Remove an environment variable
 * @name: Name of the environment variable
 *
 * Return: 0 on success, -1 on error
 */
int _unsetenv(const char *name)
{
	int i, j;
	int len = strlen(name);

	for (i = 0; environ[i]; i++)
	{
		if (strncmp(name, environ[i], len) == 0 && environ[i][len] == '=')
		{
			for (j = i; environ[j]; j++)
			{
				environ[j] = environ[j + 1];
			}
			return (0);
		}
	}
	return (-1);
}
