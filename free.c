#include "shell.h"

/**
 * free_all - A function to free a double pointer.
 * @argv: Double pointer to an array of strings.
 */

void free_all(char **argv)
{
	int i = 0;

	if(!argv)
		return;

	for (i = 0; argv[i] != NULL; i++)
	{
		free(argv[i]);
	}
	free(argv);
}
