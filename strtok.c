#include "shell.h"
/**
 * str_tok - convert strings into tokens using identified delimiters
 * @str: string to be tokenized
 * @delim: token delimiter
 * Return: token
 */
char *str_tok(char *str, const char *delim)
{
	static char *next_token;
	char *delimiter;

	if (str == NULL)
	{
		str = next_token;
	}

	if (str == NULL || *str == '\0')
	{
		return (NULL);
	}

	delimiter = strpbrk(str, delim);

	if (delimiter == NULL)
	{
		next_token = NULL;
		return (str);
	}
	*delimiter = '\0';
	next_token = delimiter + 1;

	return (str);
}
