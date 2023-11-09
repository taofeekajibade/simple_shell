#include "shell.h"
/**
 * get_line - read user input
 * Return: line read from the stdin
 */
char *get_line(void)
{
	static char buffer[BUFFER_SIZE];
	static size_t pos;
	static size_t full;
	char *line = NULL;
	int c;

	while ((c =  getchar()) != EOF && c != '\n')
	{
		if (pos == BUFFER_SIZE - 1)
		{
			full = 1;
		}
		if (!full)
		{
			buffer[pos++] = c;
		}
	}
	if (pos > 0)
	{
		line = malloc(pos + 1);
		if (line == NULL)
		{
			free(line);
			line = NULL;
		}
		memcpy(line, buffer, pos);
		line[pos] = '\0';
		pos = 0;
		full = 0;
	}
	return (line);
}

/**
 * read_line- Function that reads lines and return them as strings
 * Return: user input
 */
char *read_line(void)
{
	char *usercmd = NULL;

	usercmd = get_line();
	if (usercmd == NULL) /* Handle CTRL + D*/
	{
		if (feof(stdin))
		{
			free(usercmd);
			write(STDOUT_FILENO, "\n", 1);
			exit(EXIT_FAILURE);
		}
		free(usercmd);
		usercmd = NULL;
	}
	return (usercmd);
}