#include "shell.h"

/**
 * tokenize_input - Custom tokenizer function (like strtok)
 * @line: The line to tokenize (or NULL to continue)
 *
 * Return: Pointer to next token, or NULL if no more
 */
char *tokenize_input(char *line)
{
	static char *current;
	char *start;

	if (line)
		current = line;

	while (*current == ' ' || *current == '\t')
		current++;

	if (*current == '\0')
		return (NULL);

	start = current;

	while (*current && *current != ' ' && *current != '\t')
		current++;

	if (*current)
	{
		*current = '\0';
		current++;
	}

	return (start);
}
