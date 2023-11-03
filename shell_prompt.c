#include "shell.h"
/**
 * shell_init - displays a prompt if shell is interactive
 *
 */
void shell_init(void)
{
	write(STDOUT_FILENO, "$ ", 2);
}

/**
 * error_handler - prints error message in fork
 * @command: error message
 */
void error_handler(const char *command)
{
	const char *error_prefix = "./hsh: 1: ";
	const char *error_message = ": command not found\n";

	write(STDERR_FILENO, error_prefix, strlen(error_prefix));
	write(STDERR_FILENO, command, strlen(command));
	write(STDERR_FILENO, error_message, strlen(error_message));
}
