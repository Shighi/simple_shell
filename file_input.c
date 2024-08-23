#include "shell.h"

/**
 * process_file - Process commands from a file
 * @filename: Name of the file to process
 *
 * Return: 0 on success, -1 on failure
 */
int process_file(char *filename)
{
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		perror("Error opening file");
		return (-1);
	}

	while ((read = getline(&line, &len, fp)) != -1)
	{
		if (line[read - 1] == '\n')
			line[read - 1] = '\0';

		handle_comments(line);
		handle_logical_operators(line);

		char **args = parse_input(line);

		execute_command(args);

		free(args);
	}

	free(line);
	fclose(fp);
	return (0);
}
