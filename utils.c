#include "shell.h"

/**
 * only_spaces - Checks for whitespace-only strings
 * @s: Input string
 * Return: 1 if only spaces/tabs, 0 otherwise
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
 * read_line - Reads a line from stdin
 * Return: Allocated string (free required), NULL on EOF/error
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
 * tokenize_input - Custom strtok implementation
 * @line: Input to tokenize (NULL to continue)
 * Return: Next token, or NULL
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

/**
 * parse_arguments - Splits line into args array
 * @line: Input string
 * @args: Array to store tokens
 */
void parse_arguments(char *line, char **args)
{
	int i = 0;
	char *token;

	while (*line == ' ' || *line == '\t')
		line++;

	token = tokenize_input(line);
	while (token && i < MAX_ARGS - 1)
	{
		args[i++] = token;
		token = tokenize_input(NULL);
	}
	args[i] = NULL;
}

/* Additional helper functions below */

/**
 * _strlen - Custom strlen
 * @s: Input string
 * Return: String length
 */
int _strlen(const char *s)
{
	int len = 0;

	while (s[len])
		len++;

	return (len);
}

/**
 * _strncmp - Custom strncmp
 * @s1: First string
 * @s2: Second string
 * @n: Max chars to compare
 * Return: Difference or 0 if equal
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	for (i = 0; i < n && s1[i] && s2[i]; i++)
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);

	if (i < n)
		return (s1[i] - s2[i]);

	return (0);
}

/**
 * _strdup - Custom strdup
 * @str: String to duplicate
 * Return: New allocated copy
 */
char *_strdup(const char *str)
{
	char *dup;
	int len, i;

	if (!str)
		return (NULL);

	len = _strlen(str);
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);

	for (i = 0; i <= len; i++)
		dup[i] = str[i];

	return (dup);
}
