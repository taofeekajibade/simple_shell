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
	char *token = strtok(input, DELIM);

	if (!tokens)
	{
		perror("hsh: allocation error");
		exit(EXIT_FAILURE);
	}
	while (token)
	{
		tokens[i] = malloc(sizeof(char) * (_strlen(token) + 1));
		if (!tokens[i])
		{
			perror("hsh: allocation error");
			free_all(tokens);
			free(token);
			exit(EXIT_FAILURE);
		}
		_strcopy(tokens[i], token);
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
		token = strtok(NULL, DELIM);
	}
	tokens[i] = NULL;
	/* Update the pointer passed as an argument */
	*argv = tokens;
	return (tokens);
}

/**
 * _strtest - Tests if a given string starts with specific characters.
 * @argv: String to test
 *
 * Return: true on success, false om failure
 */
bool _strtest(char *argv)
{
	int i;
	char control[] = "/usr/bin/";

	int cntrl_len = _strlen(control);
	int arg_len = _strlen(argv);

	if (cntrl_len > arg_len)
		return (false);

	for (i = 0; i < cntrl_len; i++)
		if (argv[i] != control[i])
			return (false);

	return (true);
}

/**
 * _testcommand - Tests if a command is executable.
 * @cmd: Command to test
 *
 * Return: Void
 */
bool _testcommand(const char *cmd)
{
	return (access(cmd, X_OK) == 0);
}
