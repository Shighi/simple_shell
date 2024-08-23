#include "shell.h"

/**
 * print_alias - Print an alias
 * @name: Name of the alias
 * @value: Value of the alias
 */
void print_alias(char *name, char *value)
{
	printf("%s='%s'\n", name, value);
}

/**
 * add_alias - Add or update an alias
 * @name: Name of the alias
 * @value: Value of the alias
 * @aliases: Array of alias structs
 * @alias_count: Pointer to the number of aliases
 */
void add_alias(char *name, char *value, alias_t *aliases, int *alias_count)
{
	int i;

	for (i = 0; i < *alias_count; i++)
	{
		if (_strcmp(aliases[i].name, name) == 0)
		{
			free(aliases[i].value);
			aliases[i].value = _strdup(value);
			return;
		}
	}

	if (*alias_count < MAX_ALIASES)
	{
		aliases[*alias_count].name = _strdup(name);
		aliases[*alias_count].value = _strdup(value);
		(*alias_count)++;
	}
}

/**
 * get_alias - Get the value of an alias
 * @name: Name of the alias
 * @aliases: Array of alias structs
 * @alias_count: Number of aliases
 *
 * Return: Value of the alias, or NULL if not found
 */
char *get_alias(char *name, alias_t *aliases, int alias_count)
{
	int i;

	for (i = 0; i < alias_count; i++)
	{
		if (_strcmp(aliases[i].name, name) == 0)
		{
			return (aliases[i].value);
		}
	}
	return (NULL);
}

/**
 * shell_alias - Builtin command: alias
 * @args: Arguments
 *
 * Return: Always returns 1, to continue execution
 */
int shell_alias(char **args)
{
	static alias_t aliases[MAX_ALIASES];
	static int alias_count;
	int i;
	char *equals;
	char *value;

	if (args[1] == NULL)
	{
		for (i = 0; i < alias_count; i++)
		{
			print_alias(aliases[i].name, aliases[i].value);
		}
	}
	else
	{
		for (i = 1; args[i] != NULL; i++)
		{
			equals = _strchr(args[i], '=');
			if (equals != NULL)
			{
				*equals = '\0';
				add_alias(args[i], equals + 1, aliases, &alias_count);
			}
			else
			{
				value = get_alias(args[i], aliases, alias_count);
				if (value != NULL)
				{
					print_alias(args[i], value);
				}
			}
		}
	}

	return (1);
}
