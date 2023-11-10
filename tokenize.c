#include "shell.h"
/**
 * parse_command - A function to tokenize user inputs.
 * @user_line: pointer to command-line arguments.
 * Return: tokens.
 */
char **parse_command(char *user_line)
{
	int bufsize = BUFFER_SIZE, i = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		free(tokens);
		write(STDERR_FILENO, "hsh: allocation error\n", 22);
		exit(EXIT_FAILURE);
	}

	token = strtok(user_line, DELIMITER);
	while (token != NULL)
	{
		tokens[i] = token;
		i++;

		if (i >= bufsize)
		{
			bufsize += BUFFER_SIZE;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				free_all(tokens);
				write(STDERR_FILENO, "hsh: allocation error\n", 22);
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, DELIMITER);
	}
	tokens[i] = NULL;
	return (tokens);
}
