#include "shell.h"

/**
 * print_to_stderr - outputs a string to stderr
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void print_to_stderr(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}
