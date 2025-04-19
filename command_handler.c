#include "shell.h"
#include <unistd.h>

/**
 * handle_command - Handles execution of command
 * @args: Argument vector
 */
void handle_command(char **args)
{
	char *command_path;

	if (!args || !args[0])
		return;

	command_path = find_command_path(args[0]);
	if (command_path)
	{
		execute_command(command_path, args);
		free(command_path);
	}
	else
	{
		write(STDERR_FILENO, "./hsh: 1: ", 10);
		write(STDERR_FILENO, args[0], _strlen(args[0]));
		write(STDERR_FILENO, ": not found\n", 13);
		last_status = 127;
	}
}
