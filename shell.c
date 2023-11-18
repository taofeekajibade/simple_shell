#include "shell.h"
/**
 * main - Entry point for simple_shell program.
 * @ac: argument count
 * @argv: command-line arguments
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
			prompt();
		input = get_line();
		if (input == NULL)
		{
			if (feof(stdin))
			{
				free(input);
				input = NULL;
				write(STDOUT_FILENO, "\n", 1);
				exit(EXIT_SUCCESS);
			}
			free(input);
			input = NULL;
			exit(EXIT_FAILURE);
		}
		input[strcspn(input, "\n")] = '\0';
		if (input[0] != '\0')
		{
			argv = parse_command(input);
			executeCommand(ac, argv, env);
			free(input);
			free(argv);
			argv = NULL;
		}
	}
	return (EXIT_SUCCESS);
}
