#include "shell.h"

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
