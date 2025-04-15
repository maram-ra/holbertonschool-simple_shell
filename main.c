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
 * prompt_user - Displays the prompt and reads the user input
 *
 * Return: The input line or NULL if there's an error
 */
char *prompt_user(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);

	read = getline(&line, &len, stdin);
	if (read == -1) /* Ctrl+D or EOF */
	{
		free(line);
		return (NULL);
	}

	if (line[read - 1] == '\n')
		line[read - 1] = '\0';

	return (line);
}

/**
 * tokenize_input - Tokenizes the input line into arguments
 * @line: The input line
 * @args: The arguments array
 *
 * Return: The number of arguments
 */
int tokenize_input(char *line, char *args[])
{
	int i = 0;

	args[i] = strtok(line, " ");
	while (args[i] != NULL && i < MAX_ARGS - 1)
	{
		i++;
		args[i] = strtok(NULL, " ");
	}
	args[i] = NULL;

	return (i);
}

/**
 * execute_command - Handles the forking and execution of commands
 * @args: The arguments array
 *
 * Return: 0 on success, -1 on failure
 */
int execute_command(char *args[])
{
	pid_t pid;
	char *command_path;

	command_path = find_command(args[0]);
	if (command_path == NULL)
	{
		fprintf(stderr, "%s: command not found\n", args[0]);
		return (-1);
	}

	pid = fork();
	if (pid == 0)
	{
		/* In child: execute the command */
		execve(command_path, args, environ);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else if (pid > 0)
	{
		/* In parent: wait for child to finish */
		wait(NULL);
		free(command_path);
	}
	else
	{
		/* Handle fork failure */
		perror("fork");
		free(command_path);
		return (-1);
	}

	return
