#include "shell.h"
/**
 * read_input - read user input
 * Return: input
 */
char *read_input(void)
{
	char *line = NULL;
	size_t bufsize = 0;

	if (getline(&line, &bufsize, stdin) == -1)
	{
		if (feof(stdin))
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		free(line);
	}
	return (line);
}
