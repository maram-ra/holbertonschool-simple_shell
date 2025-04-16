#include "shell.h"

/**
 * handle_command - Handles execution of a command
 * @args: Array of arguments
 */
void handle_command(char **args)
{
	char *path_cmd;
	pid_t pid;
	int status;

	if (args[0][0] != '/' && args[0][0] != '.')
	{
		path_cmd = find_command_path(args[0]);

		if (!path_cmd)
		{
			fprintf(stderr, "%s: command not found\n", args[0]);
			return;
		}
	}
	else
	{
		path_cmd = strdup(args[0]);
		if (!path_cmd)
		{
			perror("strdup failed");
			return;
		}
	}

	pid = fork();
	if (pid == 0)
{
	execve(path_cmd, args, environ);
	fprintf(stderr, "%s: not found\n", args[0]);
	free(path_cmd);
	exit(127);
}


	else if (pid > 0)
		waitpid(pid, &status, 0);
	else
		perror("fork failed");

	free(path_cmd);
}

/**
 * main - Entry point for the simple shell
 *
 * Return: Always 0 on success
 */
int main(void)
{
	char *line;
	char *args[MAX_ARGS];

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);

		line = read_line();
		if (line == NULL)
			break;

		parse_arguments(line, args);

		if (args[0] != NULL)
			handle_command(args);

		free(line);
	}

	return (0);
}

