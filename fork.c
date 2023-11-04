#include "shell.h"
/**
 * fork_process - function to process a command
 * @ac: argument count
 * @argv: argument vectors
 * @env: environment variables
 */
void fork_process(int ac __attribute__((unused)), char **argv, char **env)
{
	int status;
	pid_t pid;
	char *path;

	path = path_to_argv(argv[0]);

	/* Create a new process */
	pid = fork();

	if (pid < 0)
	{
		perror("hsh");
		exit(EXIT_FAILURE);
	}
	/* begin the child process to execute the command */
	else if (pid == 0)
	{
		/* Test if the command is executable */
		if (access(path, F_OK) == -1)
		{
			error_handler(argv[0]);
			_exit(errno);
		}
		else if (execve(path, argv, env) == -1)
		{
			error_handler(argv[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/* In the parent process, wait for the child to complete*/
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			WEXITSTATUS(status);
	}
}
/**
 * executeCommand - executes user commands
 * @ac: argument count
 * @argv: argument vectors
 * @env: environment variables
 */
void executeCommand(int ac, char **argv, char **env)
{

	if (argv[0] == NULL)
		return;
	if (str_cmp(argv[0], "exit") == 0)
	{
		handle_exit(argv);
	}
	else if (str_cmp(argv[0], "cd") == 0)
	{
		handle_cd(argv[1]);
	}
	else if (str_cmp(argv[0], "setenv") == 0)
	{
		set_env(argv);
	}
	else if (str_cmp(argv[0], "unsetenv") == 0)
	{
		unset_env(argv);
	}
	else if (str_cmp(argv[0], "env") == 0)
	{
		print_env(env);
	}
	else
	{
		fork_process(ac, argv, env);
	}
}
