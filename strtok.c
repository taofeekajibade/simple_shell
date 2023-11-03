#include "shell.h"
/**
 * count_tokens - counts the number of tokens in input
 * @str: strings of argument
 * @delim: delimiter to input
 * Return: number of tokens
 */
int count_tokens(char *str, const char *delim)
{
	int count = 0;
	char *copy = strdup(str);
	char *token = str_tok(copy, delim);

	while (token != NULL)
	{
		count++;
		token = str_tok(NULL, delim);
	}
	free(copy);
	return (count);
}

/**
 * allocate_argv - allocates memory for argv
 * @usercmd: input from user
 * @delim: delimiter of array of user inputs
 * Return: argv with dynamically alocated memory
 */
char **allocate_argv(char *usercmd, const char *delim)
{
	int i;
	char *token;
	int num_tokens = count_tokens(usercmd, delim);
	char **argv = malloc(sizeof(char *) * (num_tokens + 1));

	if (argv == NULL)
	{
		perror("hsh: allocation error\n");
		exit(EXIT_FAILURE);
	}

	i = 0;
	token = str_tok(usercmd, delim);
	while (token != NULL)
	{
		argv[i] = strdup(token);
		i++;
		token = str_tok(NULL, delim);
	}
	argv[i] = NULL;

	return (argv);
}

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
