#include "shell.h"
/**
 * main - Entry point for simple_shell program.
 * @ac: argument count
 * @argv: argument vectors
 * @env: environment variables
 * Return: 0 on success, 1 on failure.
 */
int main(int ac, char **argv, char **env)
{
	char *input = NULL;
	int i, is_terminal = isatty(STDIN_FILENO);

	signal(SIGINT, signal_c);
	while (1)
	{
		if (is_terminal)
			write(STDOUT_FILENO, "$ ", 2);
		input = read_line();

		argv = parse_input(input, &argv);

		executeCommand(ac, argv, env);

		for (i = 0; argv[i] != NULL; i++)
		{
			free(argv[i]);
		}
		free(argv);
		free(input);
		input = NULL;

		/*
		if (input)
		{
			input[strcspn(input, "\n")] = '\0';
			if (input[0] != '\0')
			{
				argv = parse_input(input, &argv);
				if (ac > 0)
				{
					executeCommand(ac, argv, env);
				}	
				free_all(argv);
			}
		}
		free(input);
		input = NULL;
		*/
	}
	free(input);
	return (0);
}