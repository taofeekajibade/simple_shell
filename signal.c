#include "shell.h"

/**
 * handle_signal - handles  ctrl+C
 * @sig: parameter
 */
void handle_signal(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n$ ", 3);
}
