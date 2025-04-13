#include "shell.h"

/**
 * tokenize_input - Splits the input string into arguments
 * @line: The input line
 *
 * Return: An array of strings (arguments), NULL on failure
 */
char **tokenize_input(char *line)
{
	char *token = NULL;
	char **tokens = malloc(sizeof(char *) * 64);
	int i = 0;

	if (!tokens)
		return (NULL);

	token = strtok(line, " ");
	while (token)
	{
		tokens[i++] = strdup(token);
		token = strtok(NULL, " ");
	}
	tokens[i] = NULL;
	return (tokens);
}
