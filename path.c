#include "shell.h"
/**
 * path_to_argv - find the path to a command
 * @command: command-line argument
 * Return: path, if found, or null, if !exist
 */
char *path_to_argv(char *command)
{
	const char *path = getenv("PATH");
	struct stat buffer;
	char *path_copy, *path_token, *file_path;
	int cmd_len, dir_len;

	if (!path)
		return (NULL);

	path_copy = strdup(path);
	if (!path_copy)
		return (NULL);
	cmd_len = str_len(command);
	path_token = str_tok(path_copy, ":");
	while (path_token != NULL)
	{
		dir_len = strlen(path_token);
		file_path = malloc(dir_len + cmd_len + 2);
		if (!file_path)
		{
			free(path_copy);
			return (NULL);
		}
		str_cpy(file_path, path_token);
		str_cat(file_path, "/");
		str_cat(file_path, command);
		if (stat(file_path, &buffer) == 0)
		{
			free(path_copy);
			return (file_path);
		}
		else
		{
			free(file_path);
			path_token = str_tok(NULL, ":");
		}
	}
	free(path_copy);
	if (stat(command, &buffer) == 0)
		return (strdup(command));
	return (NULL);
}
