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

	/* تحقق إذا الأمر ليس مسار مباشر */
	if (args[0][0] != '/' && args[0][0] != '.')
	{
		path_cmd = find_command_path(args[0]);
		if (!path_cmd)
		{
			fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
			exit(127);
		}
	}
	else
	{
		path_cmd = strdup(args[0]);
		if (!path_cmd)
		{
			perror("strdup failed");
			exit(EXIT_FAILURE);
		}
	}

	pid = fork();
	if (pid == -1)
	{
		perror("fork failed");
		free(path_cmd);
		exit(EXIT_FAILURE);
	}

	if (pid == 0)
	{
	execve(path_cmd, args, environ);
	fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
	free(path_cmd);
	exit(127);

	}
	else
	{
		waitpid(pid, &status, 0);
	}

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

