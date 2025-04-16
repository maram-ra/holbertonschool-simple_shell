#include "shell.h"

/**
 * find_full_path - Finds the full path of a command using PATH
 * @command: The command to find (e.g., "ls")
 *
 * Return: Full path (must be freed), or NULL if not found
 */
char *find_full_path(char *command)
{
	char *path_env = getenv("PATH");
	char *path_copy, *dir, *full_path;
	int len;

	if (!path_env)
		return (NULL);

	path_copy = strdup(path_env);
	if (!path_copy)
		return (NULL);

	dir = strtok(path_copy, ":");

	while (dir)
	{
		len = strlen(dir) + strlen(command) + 2;
		full_path = malloc(len);
		if (!full_path)
		{
			free(path_copy);
			return (NULL);
		}

		sprintf(full_path, "%s/%s", dir, command);

		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		}

		free(full_path);
		dir = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}
