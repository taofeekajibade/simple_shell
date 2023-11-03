#include "shell.h"
/**
 * handle_cd - changes directory
 * @path: working directory path
 */
void handle_cd(const char *path)
{
	char *current_dir = getcwd(NULL, 0);

	if (path == NULL || str_cmp(path, "") == 0)
	{
		path = getenv("HOME");
	}
	else if (str_cmp(path, "-") == 0)
	{
		path = getenv("OLDPWD");
	}
	if (current_dir == NULL)
	{
		perror("getcwd");
		return;
	}
	if (chdir(path) == -1)
	{
		perror("chdir");
		free(current_dir);
		return;
	}
	if (setenv("PWD", getcwd(NULL, 0), 1) == -1)
	{
		perror("setenv");
	}
	if (setenv("OLDPWD", current_dir, 1) == -1)
	{
		perror("setenv");
	}
	free(current_dir);
}
