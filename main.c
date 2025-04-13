#include "shell.h"

/**
 * main - Basic shell loop
 * Return: 0 on success
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char *args[2];

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);

		read = getline(&line, &len, stdin);
		if (read == -1) /* Ctrl+D */
			break;

		if (line[read - 1] == '\n')
			line[read - 1] = '\0';

		args[0] = line;
		args[1] = NULL;

		if (fork() == 0)
		{
			execve(args[0], args, environ);
			perror("execve");
			exit(1);
		}
		else
			wait(NULL);
	}
	free(line);
	return (0);
}

