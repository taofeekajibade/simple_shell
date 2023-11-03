#include "shell.h"
/**
 * _fexit - A function to exit the shell.
 * @argv: Double pointer to an array of strings.
 */
void handle_exit(char **argv)
{
	int i, status;

	if (argv[1] != NULL)
	{
		for (i = 0; argv[1][i]; i++)
		{
			if (!isdigit(argv[1][i]))
			{
				write(2, INVALID_EXIT, sizeof(INVALID_EXIT) - 1);
				exit(EXIT_FAILURE);
			}
		}
		status = atoi(argv[1]);

		if (status < 0 || status > 255)
		{
			write(2, OUT_OF_RANGE, sizeof(OUT_OF_RANGE) - 1);
			exit(EXIT_FAILURE);
		}
		exit(status);
	}
	else
	{
		exit(EXIT_SUCCESS);
	}
}

/**
 * set_env - set environment variable
 * @argv: command-line arguments
 * Return: 0 on success, -1 on failure
 */
int set_env(char **argv)
{
	if (argv[1] == NULL || argv[2] == NULL)
	{
		write(2, "Usage: setenv VARIABLE VALUE\n", 25);
		return (-1);
	}
	if (setenv(argv[1], argv[2], 1) != 0)
	{
		perror("setenv");
		return (-1);
	}
	return (0);
}

/**
 * unset_env - unset environment variable
 * @argv: command-line arguments
 * Return: 0 on success, -1 on failure
 */
int unset_env(char **argv)
{
	if (argv[1] == NULL)
	{
		write(2, "Usage: unsetenv VARIABLE\n", 21);
		return (-1);
	}
	if (unsetenv(argv[1]) != 0)
	{
		perror("unsetenv");
		return (-1);
	}
	return (0);
}
