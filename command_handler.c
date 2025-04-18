#include "shell.h"

/**
 * handle_command - Handles execution of command
 * @args: Argument vector
 */
void handle_command(char **args)
{
	char *command_path;

	if (!args || !args[0])  /* If no command, do nothing */
		return;

	command_path = find_command_path(args[0]);  /* Find the command path */
	if (command_path)  /* If found */
	{
		execute_command(command_path, args);  /* Execute the command */
		free(command_path);  /* Free the command path after execution */
	}
	else  /* Command not found */
	{
		write(STDERR_FILENO, args[0], _strlen(args[0]));  /* Print command name */
		write(STDERR_FILENO, ": command not found\n", 20);  /* Print error message */
		last_status = 127;  /* Set the last status to indicate failure */
	}
}
