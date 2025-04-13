#include "shell.h"

#define MAX_ARGS 64

/**
 * only_spaces - Checks if a line contains only whitespace
 * @s: The input string
 *
 * Return: 1 if only spaces, 0 otherwise
 */
int only_spaces(char *s)
{
	while (*s)
	{
		if (*s != ' ' && *s != '\t' && *s != '\n')
			return (0);
		s++;
	}
	return (1);
}

/**
 * main - Basic shell loop (handles whitespace and arguments)
 *
 * Return: 0 on success
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char *args[MAX_ARGS];
	int i;
	pid_t pid;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);

		read = getline(&line, &len, stdin);
		if (read == -1) /* Ctrl+D */
			break;

		if (line[read - 1] == '\n')
			line[read - 1] = '\0';

		if (only_spaces(line))
			continue;

		/* Tokenize the line */
		i = 0;
		args[i] = strtok(line, " ");
		while (args[i] != NULL && i < MAX_ARGS - 1)
		{
			i++;
			args[i] = strtok(NULL, " ");
		}
		args[i] = NULL;

		if (args[0] == NULL)
			continue;

		pid = fork();
		if (pid == 0)
		{
			execve(args[0], args, environ);
			perror("execve");
			exit(EXIT_FAILURE);
		}
		else
			wait(NULL);
	}

	free(line);
	return (0);
}

