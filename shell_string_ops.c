#include "shell.h"

/**
 * string_copy_n - Copies up to n characters from a string
 * @destination: The destination string to copy to
 * @source: The source string
 * @max_chars: The maximum number of characters to be copied
 * Return: The resulting string
 */
char *string_copy_n(char *destination, char *source, int max_chars)
{
	int src_index, dest_index;
	char *result = destination;

	src_index = 0;
	while (source[src_index] != '\0' && src_index < max_chars - 1)
	{
		destination[src_index] = source[src_index];
		src_index++;
	}
	if (src_index < max_chars)
	{
		for (dest_index = src_index; dest_index < max_chars; dest_index++)
		{
			destination[dest_index] = '\0';
		}
	}
	return (result);
}

/**
 * string_concat_n - Concatenates n bytes from a string
 * @destination: The first string
 * @source: The second string
 * @max_bytes: The maximum number of bytes to be used
 * Return: The concatenated string
 */
char *string_concat_n(char *destination, char *source, int max_bytes)
{
	int dest_index, src_index;
	char *result = destination;

	dest_index = 0;
	src_index = 0;
	while (destination[dest_index] != '\0')
		dest_index++;
	while (source[src_index] != '\0' && src_index < max_bytes)
	{
		destination[dest_index] = source[src_index];
		dest_index++;
		src_index++;
	}
	if (src_index < max_bytes)
		destination[dest_index] = '\0';
	return (result);
}

/**
 * string_find_char - Locates a character in a string
 * @str: The string to be searched
 * @character: The character to look for
 * Return: A pointer to the first occurrence of the character in the string
 */
char *string_find_char(char *str, char character)
{
	do {
		if (*str == character)
			return (str);
	} while (*str++ != '\0');

	return (NULL);
}
