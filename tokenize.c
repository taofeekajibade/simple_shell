#include "shell.h"
/**
 * parse_input - A function to tokenize user inputs.
 * @argv: pointer to command-line arguments.
 * @input: command-line arguments.
 * Return: tokens.
 */
char **parse_input(char *input, char ***argv)
{
	size_t i = 0, token_size = MAX_INPUT;
	char **tokens = malloc(token_size * sizeof(char *));
	char *token = str_tok(input, DELIM);

	if (!tokens)
	{
		perror("hsh: allocation error");
		exit(EXIT_FAILURE);
	}
	while (token)
	{
		tokens[i] = malloc(sizeof(char) * (str_len(token) + 1));
		if (!tokens[i])
		{
			perror("hsh: allocation error");
			free_all(tokens);
			free(token);
			exit(EXIT_FAILURE);
		}
		str_cpy(tokens[i], token);
		i++;
		if (i >= token_size)
		{
			token_size *= 2;
			tokens = realloc(tokens, token_size * sizeof(char *));
			if (!tokens)
			{
				perror("hsh: allocation error");
				free_all(tokens);
				free(token);
				exit(EXIT_FAILURE);
			}
		}
		token = str_tok(NULL, DELIM);
	}
	tokens[i] = NULL;
	/* Update the pointer passed as an argument */
	*argv = tokens;
	return (tokens);
}

/**
 * str_test - Tests if a given string starts with specific characters.
 * @argv: String to test
 *
 * Return: true on success, false om failure
 */
bool str_test(char *argv)
{
	int i;
	char control[] = "/usr/bin/";

	int cntrl_len = str_len(control);
	int arg_len = str_len(argv);

	if (cntrl_len > arg_len)
		return (false);

	for (i = 0; i < cntrl_len; i++)
		if (argv[i] != control[i])
			return (false);

	return (true);
}

/**
 * test_command - Tests if a command is executable.
 * @cmd: Command to test
 *
 * Return: Void
 */
bool test_command(const char *cmd)
{
	return (access(cmd, X_OK) == 0);
}
