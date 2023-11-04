#include "shell.h"

/**
 * signal_c - handles  ctrl+C
 * @sig: parameter
 */
void signal_c(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n$ ", 3);
}
