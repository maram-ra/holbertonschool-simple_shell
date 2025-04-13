#include "shell.h"

/**
 * execute_command - Executes a command using fork + execve
 * @args: Array of command + arguments
 * @program_name: Name of the shell program (used in error)
 *
 * Return: 1 to keep shell running
 */
int execute_command(char **args, char *program_name)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == -1)
	{
		perror("fork");
		return (1);
	}

	if (pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			perror(program_name);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
	}

	return (1);
}
