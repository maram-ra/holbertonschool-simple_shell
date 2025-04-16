#include "shell.h"
#include <sys/stat.h>

/**
 * build_path - Build full path from directory and command
 * @dir: directory path
 * @cmd: command name
 *
 * Return: full path string or NULL on failure
 */
char *build_path(char *dir, char *cmd)
{
	char *full_path;
	int len = _strlen(dir) + _strlen(cmd) + 2;

	full_path = malloc(len);
	if (!full_path)
		return (NULL);

	sprintf(full_path, "%s/%s", dir, cmd);
	return (full_path);
}

/**
 * find_command_path - Search for a command in the PATH
 * @cmd: command to find
 *
 * Return: full path or NULL
 */
char *find_command_path(char *cmd)
{
	struct stat st;
	char *path = get_env_value("PATH");
	char *token, *dup, *full_path;

	if (!path)
		return (NULL);

	if (strchr(cmd, '/'))
	{
		if (stat(cmd, &st) == 0)
			return (_strdup(cmd));
		return (NULL);
	}

	dup = _strdup(path);
	token = strtok(dup, ":");

	while (token)
	{
		full_path = build_path(token, cmd);
		if (!full_path)
		{
			free(dup);
			return (NULL);
		}

		if (stat(full_path, &st) == 0)
		{
			free(dup);
			return (full_path);
		}

		free(full_path);
		token = strtok(NULL, ":");
	}
	free(dup);
	return (NULL);
}
