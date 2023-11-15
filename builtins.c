#include "shell.h"
/**
 * handle_exit - A function to exit the shell.
 * @argv: pointer exit argument.
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
				free(argv);
				write(3, "exit code is invalid\n", 21);
				exit(EXIT_FAILURE);
			}
		}
		status = atoi(argv[1]);
		free_all(argv);

		if (status < 0 || status > 255)
		{
			free(argv);
			write(3, "value entered is out of range\n", 30);
			exit(EXIT_FAILURE);
		}
		argv = NULL;
		exit(status);
	}
	else
	{
		free_all(argv);
		exit(EXIT_SUCCESS);
	}
}

/**
 * handle_cd - changes directory
 * @argv: working directory path
 */
void handle_cd(char **argv)
{
	char *current_dir = getcwd(NULL, 0);

	if (current_dir == NULL)
	{
		free(current_dir);
		perror("cannot access working directory");
		return;
	}
	if (argv[1] == NULL || str_cmp(argv[1], "") == 0)
	{
		argv[1] = getenv("HOME");
	}
	if (str_cmp(argv[1], "-") == 0)
	{
		argv[1] = getenv("OLDPWD");
	}
	if (chdir(argv[1]) == -1)
	{
		p_error(argv[1]);
		free(current_dir);
		return;
	}
	if (setenv("PWD", getcwd(NULL, 0), 1) == -1)
	{
		perror("Unable to set PWD");
		free(current_dir);
		return;
	}
	if (setenv("OLDPWD", current_dir, 1) == -1)
	{
		perror("Unable to set OLDPWD");
		free(current_dir);
		return;
	}
	free(current_dir);
	current_dir = NULL;
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
		write(2, "Usage: setenv VARIABLE VALUE\n", 29);
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
		write(2, "Usage: unsetenv VARIABLE\n", 25);
		return (-1);
	}
	if (unsetenv(argv[1]) != 0)
	{
		perror("unsetenv");
		return (-1);
	}
	return (0);
}

/**
 * print_env - prints environment variables
 * @env: environment variables
 */
void print_env(char **env)
{
	int i;

	if (env == NULL)
		return;

	for (i = 0; env[i] != NULL; i++)
	{
		write(1, env[i], strlen(env[i]));
		write(1, "\n", 1);
	}
}
