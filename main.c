#include "shell.h"

/**
 * main - Entry point of the shell
 * @argc: Argument count (unused)
 * @argv: Argument vector (used for program name)
 *
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char **args;
	int status = 1;

	(void)argc;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			shell_prompt();

		read = getline(&line, &len, stdin);
		if (read == -1)
			break;

		if (line[read - 1] == '\n')
			line[read - 1] = '\0';

		args = tokenize_input(line);
		if (!args || !args[0])
		{
			free_array(args);
			continue;
		}

		status = execute_command(args, argv[0]);
		free_array(args);
	}

	free(line);
	return (status);

}
