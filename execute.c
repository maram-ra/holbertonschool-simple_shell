#include "shell.h"

char *fullpath = NULL;

/**
 * printerror - prints error
 * @command: command inserted
 */
void printerror(char *const command[])
{
	fprintf(stderr, "./hsh: 1: %s: not found\n", command[0]);
	exit(127);
}

/**
 * _getenv - get environment variable
 * @name: name of environment variable
 * @envp: pointer to environment variables
 * Return: pointer to environment variable
 */
char *_getenv(const char *name, char **envp)
{
	char **env;
	char *separator;

	for (env = envp; *env != NULL; env++)
	{
		separator = strchr(*env, '=');
		if (separator != NULL)
		{
			if (strncmp(*env, name, separator - *env) == 0)
				return (separator + 1);
		}
	}
	return (NULL);
}

/**
 * pathfinder - finds the correct path for given alias
 * @cmd: command to find in PATH
 * @command: command array to update
 * @envp: pointer to environment variables
 * Return: updated command or NULL if not found
 */
char **pathfinder(char *cmd, char **command, char **envp)
{
	char *current_path, *temp_path;
	char *path_tok;
	size_t arglen = strlen(cmd);

	if (strchr(cmd, '/') != NULL && access(cmd, F_OK) == 0)
	{
		command[0] = cmd;
		return (command);
	}

	current_path = _getenv("PATH", envp);
	if (current_path == NULL)
		return (NULL);

	temp_path = strdup(current_path);
	if (!temp_path)
		return (NULL);

	path_tok = strtok(temp_path, ":");
	while (path_tok)
	{
		fullpath = malloc(arglen + strlen(path_tok) + 2);
		if (!fullpath)
		{
			free(temp_path);
			return (NULL);
		}

		sprintf(fullpath, "%s/%s", path_tok, cmd);

		if (access(fullpath, F_OK) == 0)
		{
			command[0] = fullpath;
			free(temp_path);
			return (command);
		}

		free(fullpath);
		fullpath = NULL;
		path_tok = strtok(NULL, ":");
	}

	free(temp_path);
	return (NULL);
}

/**
 * execute - function to execute commands
 * @command: input from user
 * @envp: environment path
 * Return: exit status code
 */
int execute(char *const command[], char **envp)
{
	pid_t id;
	int status;
	char **temp = pathfinder(command[0], (char **)command, envp);

	if (temp != NULL)
	{
		id = fork();
		if (id < 0)
		{
			perror("fork failed");
			return (-1);
		}
		else if (id == 0)
		{
			execve(temp[0], command, envp);
			perror("execve failed");
			exit(errno == ENOENT ? 127 : 2);
		}
		waitpid(id, &status, 0);

		if (fullpath)
		{
			free(fullpath);
			fullpath = NULL;
		}

		if (WIFEXITED(status))
			return (WEXITSTATUS(status));
	}
	else
	{
		printerror(command);
	}

	return (2);
}
