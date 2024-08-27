#include "shell.h"

/**
 * pid_to_str - Converts a process ID to a string
 * @pid: The process ID to convert
 *
 * Return: A string representation of the process ID
 */
char *pid_to_str(pid_t pid)
{
	static char str[20];

	sprintf(str, "%d", pid);
	return (str);
}

/**
 * int_to_str - Converts an integer to a string
 * @num: The integer to convert
 *
 * Return: A string representation of the integer
 */
char *int_to_str(int num)
{
	static char str[20];

	sprintf(str, "%d", num);
	return (str);
}
