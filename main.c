#include "shell.h"

/**
 * display_prompt - Displays the shell prompt if in interactive mode
 */
void display_prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
}

/**
 * process_input - Reads, parses, and handles input
 * @args: Array to hold parsed arguments
 * @len: Pointer to buffer length
 *
 * Return: 1 to continue loop, 0 to break
 */
int process_input(char **args, size_t *len)
{
	ssize_t read = getline(&line, len, stdin);

	if (read == -1)
		return (0);

	if (line[read - 1] == '\n')
		line[read - 1] = '\0';

	if (!only_spaces(line))
	{
		parse_arguments(line, args);
		if (args[0] != NULL)
		{
			if (check_builtin(args))
				return (1);
			handle_command(args);
		}
	}

	return (1);
}

/**
 * main - Entry point for the simple shell
 *
 * Return: Always 0
 */
int main(void)
{
	size_t len = 0;
	char *args[MAX_ARGS];

	display_prompt();

	while (process_input(args, &len))
		display_prompt();

	free(line);
	return (last_status);
}
