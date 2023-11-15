#include "shell.h"
/**
 *str_cmp - Function that that compares two character strings
 *@str1: string 1
 *@str2: string 2
 *Return: 0 if strings are same or -1 on failure
 */
int str_cmp(const char *str1, const char *str2)
{
	while (*str1 && *str2 && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}

/**
 * error_handler - prints error message in fork
 * @command: error message
 */
void error_handler(const char *command)
{
	const char *error_prefix = "hsh: ";
	const char *error_message = ": command not found\n";

	write(STDERR_FILENO, error_prefix, strlen(error_prefix));
	write(STDERR_FILENO, command, strlen(command));
	write(STDERR_FILENO, error_message, strlen(error_message));
}


/**
 * p_error - prints error message in cd
 * @command: command-line argument
 */
void p_error(const char *command)
{
	const char *error_prefix = "hsh: cd: ";
	const char *error_message = ": No such file or directory\n";

	write(STDERR_FILENO, error_prefix, strlen(error_prefix));
	write(STDERR_FILENO, command, strlen(command));
	write(STDERR_FILENO, error_message, strlen(error_message));
}
