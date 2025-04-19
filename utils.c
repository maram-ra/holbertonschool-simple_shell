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

	while (*line == ' ' || *line == '\t')
		line++;

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
 * _strlen - Calculates the length of a string (like strlen)
 * @s: The input string
 *
 * Return: Length of the string
 */
int _strlen(const char *s)
{
	int len = 0;

	while (s[len])
		len++;

	return (len);
}

/**
 * _strncmp - Compares two strings up to n bytes (like strncmp)
 * @s1: First string
 * @s2: Second string
 * @n: Number of characters to compare
 *
 * Return: 0 if strings are equal up to n, otherwise difference
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	for (i = 0; i < n && s1[i] && s2[i]; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}

	if (i < n)
		return (s1[i] - s2[i]);

	return (0);
}
