#include "shell.h"

/**
 * main - Entry point for the simple shell
 *
 * Description: This function runs a basic shell loop that reads input
 * from the user, parses it into commands and arguments, finds the full
 * path to the executable, and runs it in a child process.
 *
 * Return: Always 0 on success
 */

int main(void)
{
	char *line;
	char *args[MAX_ARGS];
	char *command_path;

	while (1)
	{
		line = read_line();
		if (line == NULL)
			break;

		parse_arguments(line, args);

		if (args[0] == NULL)
		{
			free(line);
			continue;
		}

		command_path = find_command_path(args[0]);
		if (command_path == NULL)
		{
			fprintf(stderr, "%s: command not found\n", args[0]);
			free(line);
			continue;
		}

		execute_command(command_path, args);

		free(command_path);
		free(line);
	}

	return (0);
}
