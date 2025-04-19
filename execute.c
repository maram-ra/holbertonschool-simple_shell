#include "shell.h"

/**
 * execute_command - Execute a command with fork and execve
 * @path: Full path to command
 * @args: Command arguments
 */
void execute_command(char *path, char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return;
	}

	if (pid == 0)
	{
		if (execve(path, args, environ) == -1)
		{
			fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
			exit(127);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
	}
}
