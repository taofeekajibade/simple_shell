#include "shell.h"

/**
 * free_all - A function to free a double pointer.
 * @argv: Double pointer to an array of strings.
 */

void free_all(char **argv)
{
	int i = 0;

	while (argv[i] != NULL)
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}
