#include "shell.h"

/**
 * printerror - print command not found error
 * @command: command inserted
 */
void printerror(char *const command[])
{
	fprintf(stderr, "./hsh: 1: %s: not found\n", command[0]);
	free(command[0]);
	exit(127);
}

/**
 * _getenv - gets environment variable
 * @name: name of environment variable
 * @envp: environment variables
 * Return: pointer to value or NULL
 */
char *_getenv(const char *name, char **envp)
{
	char **env;
	char *separator;

	for (env = envp; *env != NULL; env++)
	{
		separator = strchr(*env, '=');
		if (separator && strncmp(*env, name, separator - *env) == 0)
			return (separator + 1);
	}
	return (NULL);
}

/**
 * pathfinder - builds full path to command
 * @cmd: command string
 * @envp: environment
 * Return: full path string or NULL
 */
char *pathfinder(char *cmd, char **envp)
{
	char *path = _getenv("PATH", envp);
	char *tok, *full;
	size_t len;

	if (!path)
		return (NULL);

	if (strchr(cmd, '/') != NULL && access(cmd, X_OK) == 0)
		return (strdup(cmd));

	path = strdup(path);
	if (!path)
		return (NULL);

	tok = strtok(path, ":");
	while (tok)
	{
		len = strlen(tok) + strlen(cmd) + 2;
		full = malloc(len);
		if (!full)
		{
			free(path);
			return (NULL);
		}
		snprintf(full, len, "%s/%s", tok, cmd);
		if (access(full, X_OK) == 0)
		{
			free(path);
			return (full);
		}
		free(full);
		tok = strtok(NULL, ":");
	}
	free(path);
	return (NULL);
}

/**
 * execute - runs the command
 * @command: command array
 * @envp: environment
 * Return: 0 on success, -1 on fail
 */
int execute(char *const command[], char **envp)
{
	pid_t pid;
	int status;
	char *fullpath;


	if (strchr(command[0], '/') != NULL)
	{
		if (access(command[0], X_OK) != 0)
		{
			printerror(command);
			return (127);
		}
		fullpath = strdup(command[0]);
	}
	else
	{
		fullpath = pathfinder(command[0], envp);
		if (!fullpath)
		{
			printerror(command);
			return (127);
		}
	}

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		free(fullpath);
		return (-1);
	}
	if (pid == 0)
	{

		execve(fullpath, command, envp ? envp : environ);
		perror("execve");
		free(fullpath);
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&status);
		free(fullpath);
	}
	return (0);
}

