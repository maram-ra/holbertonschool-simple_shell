#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

/**
 * find_command_path - Searches for a command in PATH
 * @command: The command to find
 * Return: Full path if found, otherwise NULL
 */
char *find_command_path(char *command)
{
	char *path_env, *path_copy, *dir;
	char full_path[1024];
	struct stat st;

	/* If the command contains '/', return directly relative or absolute path */
	if (strchr(command, '/'))
	{
		if (stat(command, &st) == 0 && (st.st_mode & S_IXUSR))
			return (strdup(command));
		return (NULL);  /* Command not found */
	}

	/* If PATH is missing or empty, we can't proceed */
	path_env = get_env_value("PATH");
	if (!path_env || *path_env == '\0')  /* If PATH is empty */
		return (NULL);

	path_copy = strdup(path_env);
	if (!path_copy)
		return (NULL);

	/* Search for the command in each directory listed in PATH */
	dir = strtok(path_copy, ":");
	while (dir)
	{
		snprintf(full_path, sizeof(full_path), "%s/%s", dir, command);
		if (stat(full_path, &st) == 0 && (st.st_mode & S_IXUSR))
		{
			free(path_copy);
			return (strdup(full_path));  /* Return the full path if found */
		}
		dir = strtok(NULL, ":");  /* Move to the next directory in PATH */
	}

	free(path_copy);  /* Free the copied PATH */
	return (NULL);  /* Command not found in PATH */
}
