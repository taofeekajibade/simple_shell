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
	char **args;
	int is_terminal = isatty(STDIN_FILENO);
	(void)argv;

	signal(SIGINT, signal_c);

	while (1)
	{
		if (is_terminal)
			write(STDOUT_FILENO, "$ ", 2);

		input = get_line();
		if (feof(stdin))
		{
			free(input);
			break;
			/*exit(EXIT_SUCCESS);*/
		}
		if (input)
		{
			input[strcspn(input, "\n")] = '\0';
			if (input[0] != '\0')
			{
				parse_input(input, &args);
				if (ac > 0)
				{
					executeCommand(ac, args, env);
				}	
				free_all(args);
			}
		}
		free(input);
		input = NULL;
	}
	free(input);
	return (0);
}