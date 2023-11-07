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
	/*char **args;*/
	int is_terminal = isatty(STDIN_FILENO);

	signal(SIGINT, signal_c);
	while (1)
	{
		if (is_terminal)
			write(STDOUT_FILENO, "$ ", 2);
		input = get_line();
		if (input == NULL)
		{
			if (feof(stdin))
			{
				free(input);
				write(STDOUT_FILENO, "\n", 1);
				break;
			}
			continue;
		}
		input[strcspn(input, "\n")] = '\0';
		if (input[0] != '\0')
		{
			argv = parse_command(input);
			if (argv)
			{
				executeCommand(ac, argv, env);
				free(argv);

			}
		}
		free(input);
		input = NULL;
	}
	return (0);
}
