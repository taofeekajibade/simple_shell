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
	int is_terminal = isatty(STDIN_FILENO);

	signal(SIGINT, signal_c);

	while (1)
	{
		if (is_terminal)
			write(STDOUT_FILENO, "$ ", 2);

		input = get_line();
		if (feof(stdin))
		{
			free(input);
			exit(EXIT_SUCCESS);
		}
		else if (input != NULL)
		{
			input[strcspn(input, "\n")] = '\0';
			if (input[0] != '\0')
			{
				parse_input(input, &argv);
				if (ac > 0)
					executeCommand(ac, argv, env);
				free_all(argv);
			}
			free(input);
			input = NULL;
		}
	}
	return (0);
}
