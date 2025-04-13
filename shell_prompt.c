#include "shell.h"

/**
 * shell_prompt - Displays the shell prompt
 */
void shell_prompt(void)
{
	write(STDOUT_FILENO, "($) ", 4);
}
