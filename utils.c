#include "shell.h"

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
 * read_line - Reads a line from standard input
 *
 * Return: Pointer to the read line (must be freed), or NULL on EOF/empty line
 */
char *read_line(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);

	read = getline(&line, &len, stdin);
	if (read == -1)
	{
		free(line);
		return (NULL);
	}

	if (line[read - 1] == '\n')
		line[read - 1] = '\0';

	if (only_spaces(line))
	{
		free(line);
		return (NULL);
	}

	return (line);
}

/**
 * parse_arguments - Tokenizes a command line into arguments
 * @line: Input command line
 * @args: Array to store the arguments
 */
void parse_arguments(char *line, char **args)
{
	int i = 0;
	char *token;

	token = tokenize_input(line);
	while (token != NULL && i < MAX_ARGS - 1)
	{
		args[i] = token;
		i++;
		token = tokenize_input(NULL);
	}
	args[i] = NULL;
}

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
