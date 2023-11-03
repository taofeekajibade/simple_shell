#include "shell.h"
/**
 * str_dup - duplicate string: not tested yet
 * @str: string to duplicate
 * Return: duplicate of string
 */
char str_dup(const char *str)
{
	size_t len = 0, i;
	char *duplicate;

	if (str == NULL)
	{
		return (-1);
	}
	while (str[len] != '\0')
	{
		len++;
	}
	duplicate = malloc(sizeof(char) * (len + 1));
	if (duplicate == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i <= len; i++)
	{
		duplicate[i] = str[i];
	}
	return (*duplicate);
}
