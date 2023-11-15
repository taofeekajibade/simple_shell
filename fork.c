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
	char *path = path_to_argv(argv[0]);

	if (!path)
	{
		perror("./hsh");
		/*error_handler(argv[0]);*/
		return;
	}
	pid = fork();
	if (pid < 0)
	{
		perror("./hsh");
		free(path);
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (access(path, X_OK) == -1)
		{
			perror("./hsh");
			/*error_handler(argv[0]);*/
			free(path);
			_exit(errno);
		}
		if (execve(path, argv, env) == -1)
		{
			perror("./hsh");
			/*error_handler(argv[0]);*/
			free(path);
			_exit(EXIT_FAILURE);
		}
	}
	else
	{
		free(path);
		waitpid(pid, &status, 0);
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
		handle_exit(argv);

	else if (str_cmp(argv[0], "cd") == 0)
		handle_cd(argv);

	else if (str_cmp(argv[0], "setenv") == 0)
		set_env(argv);

	else if (str_cmp(argv[0], "unsetenv") == 0)
		unset_env(argv);

	else if (str_cmp(argv[0], "env") == 0)
		print_env(env);

	else
		fork_process(ac, argv, env);
}
