#include "shell.h"
/**
 * parse_input - A function to tokenize user inputs.
 * @argv: pointer to command-line arguments.
 * @input: command-line arguments.
 * Return: tokens.
 */
char **parse_input(char *input, char ***argv)
{
	size_t i = 0, token_size = BUFFER_SIZE;
	char **tokens = malloc(token_size * sizeof(char *));
	char *token = str_tok(input, DELIMITER);

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
				exit(EXIT_FAILURE);
			}
		}
		token = str_tok(NULL, DELIMITER);
	}
	tokens[i] = NULL;
	*argv = tokens;
	return (tokens);
}