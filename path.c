#include "shell.h"
#include <sys/stat.h>

/**
 * find_command - Search for a command in the PATH
 * @cmd: The command to find
 *
 * Return: Full path to the command, or NULL if not found
 */
char *find_command(char *cmd)
{
	char *path = getenv("PATH");
	char *token, *full_path;
	struct stat st;

	if (!path)
		return (NULL);

	/* If the command contains '/', assume it's an absolute/relative path */
	if (strchr(cmd, '/'))
	{
		if (stat(cmd, &st) == 0)
			return (strdup(cmd));
		return (NULL);
	}

	token = strtok(strdup(path), ":");
	while (token)
	{
		full_path = malloc(strlen(token) + strlen(cmd) + 2);
		if (!full_path)
			return (NULL);
		sprintf(full_path, "%s/%s", token, cmd);

		if (stat(full_path, &st) == 0)
			return (full_path); /* success */

		free(full_path);
		token = strtok(NULL, ":");
	}

	return (NULL);
}
