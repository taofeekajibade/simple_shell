#include "shell.h"
/**
 * get_path - find the path to a command
 * @command: command-line argument
 * Return: path, if found, or null, if !exist
 */
char *get_path(char *command)
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
	cmd_len = _strlen(command);
	path_token = strtok(path_copy, ":");
	while (path_token != NULL)
	{
		dir_len = strlen(path_token);
		file_path = malloc(dir_len + cmd_len + 2);
		if (!file_path)
		{
			free(path_copy);
			return (NULL);
		}
		_strcopy(file_path, path_token);
		_strcat(file_path, "/");
		_strcat(file_path, command);
		if (stat(file_path, &buffer) == 0)
		{
			free(path_copy);
			return (file_path);
		}
		else
		{
			free(file_path);
			path_token = strtok(NULL, ":");
		}
	}
	free(path_copy);
	if (stat(command, &buffer) == 0)
		return (strdup(command));
	return (NULL);
}
