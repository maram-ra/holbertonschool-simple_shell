#include "shell.h"

/**
 * check_builtin - Checks if the command is a built-in and executes it
 * @args: Parsed arguments from user input
 *
 * Return: 1 if a built-in was handled, 0 otherwise
 */
int check_builtin(char **args)
{
	if (_strncmp(args[0], "exit", 4) == 0 && args[1] == NULL)
	{
		free_args_and_exit(); /* handle memory and exit */
	}
	return (0);
}

/**
 * free_args_and_exit - Frees memory and exits shell
 */
void free_args_and_exit(void)
{
	/* Add any other cleanup logic if needed */
	exit(last_status);
}
